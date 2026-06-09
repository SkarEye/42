/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:34:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 12:52:58 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#include "ShrubberyCreationForm.hpp"

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

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("blank")
{	LOG_DEBUG("[ShrubberyCreationForm] Default constructor called");}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{	LOG_DEBUG("[ShrubberyCreationForm] Parameterized constructor called");}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target)
{	LOG_DEBUG("[ShrubberyCreationForm] Copy constructor called");}

ShrubberyCreationForm::~ShrubberyCreationForm()
{	LOG_DEBUG("[ShrubberyCreationForm] Destructor called");}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	LOG_DEBUG("[ShrubberyCreationForm] Copy assignment operator called");

	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& e) const
{
	AForm::execute(e);
	
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	if (!ofs)
	{
		std::cerr << ANSI_RED "Could not open " << filename << ANSI_RESET << std::endl;
		return ;
	}

	ofs <<
		"       _-_\n"
		"    /~~   ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n"
		"  _ -  | |   -_\n"
		"      // \\\\\n";
}
