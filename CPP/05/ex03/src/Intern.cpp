/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:51:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 15:50:29 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

#define ANSI_RESET		"\033[0m"
#define ANSI_RED		"\033[31m"

#ifdef DEBUG

# define ANSI_BOLD		"\033[1m"


# define ANSI_MAGENTA	"\033[35m"
# define ANSI_BMAGENTA	"\033[95m"

# define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BMAGENTA << ANSI_BOLD \
					<< "[DEBUG] " \
					<< ANSI_RESET << ANSI_MAGENTA \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#else
# define LOG_DEBUG(x) do {} while (0)
#endif

static AForm*	makeShrubbery(const std::string& target)
{   return new ShrubberyCreationForm(target); }

static AForm*	makeRobotomy(const std::string& target)
{   return new RobotomyRequestForm(target); }

static AForm*	makePresidential(const std::string& target)
{   return new PresidentialPardonForm(target); }

Intern::Intern(void)
{	LOG_DEBUG("[Intern] Default constructor called");}

Intern::Intern(const Intern& other)
{	(void)other; LOG_DEBUG("[Intern] Copy constructor called");}

Intern::~Intern(void)
{	LOG_DEBUG("[Intern] Destructor called");}

Intern&	Intern::operator=(const Intern& other)
{
	LOG_DEBUG("[Intern] Assignment operator called");
	(void)other;
	return (*this);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	typedef	AForm* (*FormFactory)(const std::string&);

	struct	Entry
	{
		const char* name;
		FormFactory	factory;
	};

	static const Entry	table[] = {
		{"shrubbery creation",   &makeShrubbery},
		{"robotomy request",     &makeRobotomy},
		{"presidential pardon", &makePresidential},
	};
	static const size_t	N = sizeof(table) / sizeof(Entry);

	for (size_t	i = 0; i < N; ++i)
	{
		if (name == table[i].name)
		{
			std::cout << "Intern creates " << name <<std::endl;
			return (table[i].factory(target));
		}
	}
	std::cerr << ANSI_RED "Intern: form `" << name << "' doesn't exist." ANSI_RESET << std::endl;
	return (NULL);
}

const char*	Intern::FormNotFoundException::what() const throw()
{
	return (ANSI_RED " Intern: requested form doesn't exist." ANSI_RESET);
}
