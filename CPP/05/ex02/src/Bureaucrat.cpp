/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:10:45 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 15:03:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

int	Bureaucrat::validateGrade(int grade)
{
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	return (grade);
}

Bureaucrat::Bureaucrat(void) :
	_name("unknown"),
	_grade(GRADE_MIN)
{	LOG_DEBUG("[Bureaucrat] Default constructor called");}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(validateGrade(grade))
{	LOG_DEBUG("[Bureaucrat] Parameterized constructor called");}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade)
{	LOG_DEBUG("[Bureaucrat] Copy constructor called");}

Bureaucrat::~Bureaucrat(void)
{	LOG_DEBUG("[Bureaucrat] Destructor called");}


Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	LOG_DEBUG("[Bureaucrat] Assignment operator called");

	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

int	Bureaucrat::getMaxGrade(void)
{
	return (GRADE_MAX);
}

int	Bureaucrat::getMinGrade(void)
{
	return (GRADE_MIN);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}

void	Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << "." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << f.getName()
				  << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& f) const
{
	try
	{
		f.execute(*this);
		std::cout << this->_name << " executed " << f.getName() << "." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << f.getName()
				  << " because " << e.what() << "." << std::endl;	
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (ANSI_RED " Bureaucrat: grade too high !" ANSI_RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (ANSI_RED " Bureaucrat: grade too low !" ANSI_RESET);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}
