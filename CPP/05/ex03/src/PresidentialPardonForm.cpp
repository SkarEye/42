/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:34:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 14:10:32 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

#define ANSI_RESET		"\033[0m"
#define ANSI_ITALIC		"\033[3m"
#define ANSI_BLACK		"\033[30m"
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

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardonForm", 25, 5),
	_target("blank")
{	LOG_DEBUG("[PresidentialPardonForm] Default constructor called");}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{	LOG_DEBUG("[PresidentialPardonForm] Parameterized constructor called");}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other._target)
{	LOG_DEBUG("[PresidentialPardonForm] Copy constructor called");}

PresidentialPardonForm::~PresidentialPardonForm()
{	LOG_DEBUG("[PresidentialPardonForm] Destructor called");}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	LOG_DEBUG("[PresidentialPardonForm] Copy assignment operator called");

	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& e) const
{
	AForm::execute(e);
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
