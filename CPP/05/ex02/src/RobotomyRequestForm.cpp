/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:34:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 14:46:24 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

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

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", 72, 45),
	_target("blank")
{	LOG_DEBUG("[RobotomyRequestForm] Default constructor called");}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{	LOG_DEBUG("[RobotomyRequestForm] Parameterized constructor called");}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target)
{	LOG_DEBUG("[RobotomyRequestForm] Copy constructor called");}

RobotomyRequestForm::~RobotomyRequestForm()
{	LOG_DEBUG("[RobotomyRequestForm] Destructor called");}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	LOG_DEBUG("[RobotomyRequestForm] Copy assignment operator called");

	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& e) const
{
	AForm::execute(e);
	
	std::cout << ANSI_BLACK ANSI_ITALIC "...zzZZZZZzzzz... Drilling noises ...zzzZZzzZzzz..." ANSI_RESET << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy of " << this->_target << " failed." << std::endl;
}
