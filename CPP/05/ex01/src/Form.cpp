/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 15:04:19 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

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

int	Form::validateGrade(int grade)
{
	if (grade < GRADE_MAX)
		throw Form::GradeTooHighException();
	if (grade > GRADE_MIN)
		throw Form::GradeTooLowException();
	return (grade);
}

Form::Form(void) :
	_name("unknown"),
	_is_signed(false),
	_sign_grade(GRADE_MIN),
	_exec_grade(GRADE_MIN)
{	LOG_DEBUG("[Form] Default constructor called");}

Form::Form(const std::string& name, int sign_grade, int exec_grade) :
	_name(name),
	_is_signed(false),
	_sign_grade(validateGrade(sign_grade)),
	_exec_grade(validateGrade(exec_grade))
{	LOG_DEBUG("[Form] Parameterized constructor called");}

Form::Form(const Form &other) :
	_name(other._name),
	_is_signed(other._is_signed),
	_sign_grade(other._sign_grade),
	_exec_grade(other._exec_grade)
{	LOG_DEBUG("[Form] Copy constructor called");}

Form::~Form(void)
{	LOG_DEBUG("[Form] Destructor called");}

Form&	Form::operator=(const Form &other)
{
	LOG_DEBUG("[Form] Assignment operator called");

	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::isSigned(void) const
{
	return (this->_is_signed);
}

int					Form::getGradeToSign(void) const
{
	return (this->_sign_grade);
}

int					Form::getGradeToExecute(void) const
{
	return (this->_exec_grade);
}

int	Form::getMaxGrade(void)
{
	return (GRADE_MAX);
}

int	Form::getMinGrade(void)
{
	return (GRADE_MIN);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return (ANSI_RED " Form: grade too high !" ANSI_RESET);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (ANSI_RED " Form: grade too low !" ANSI_RESET);
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\" "
	<< "[signed: " << (f.isSigned() ? "yes" : "no")
	<< ", sign grade: " << f.getGradeToSign()
	<< ", exec grade: " << f.getGradeToExecute() << "]";
	return (os);
}
