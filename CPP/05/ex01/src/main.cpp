/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:55:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 14:31:39 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define ANSI_RESET	"\033[0m"
#define ANSI_BOLD	"\033[1m"

#define ANSI_CYAN	"\033[36m"
#define ANSI_GREEN	"\033[32m"
#define ANSI_RED	"\033[31m"
#define ANSI_YELLOW	"\033[33m"

#define LOG_INFO(x)	std::cout << ANSI_CYAN		<< x << ANSI_RESET
#define LOG_TEST(x)	std::cout << ANSI_YELLOW	<< ANSI_BOLD << "\n--- " << x << " ---" << ANSI_RESET << std::endl
#define LOG_OK(x)	std::cout << ANSI_GREEN		<< "[ OK ] "   << ANSI_RESET << x << std::endl
#define LOG_FAIL(x)	std::cout << ANSI_RED		<< "[FAIL] "   << ANSI_RESET << x << std::endl

int main(void)
{
	LOG_INFO("Starting test suite...\n\n");

	LOG_TEST("Valid Form construction (1/8)");
	{
		try
		{
			Form f("Tax Report", 50, 25);
			std::cout << f << std::endl;
			LOG_OK("Form constructed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Form sign_grade too high (2/8)");
	{
		try
		{
			Form f("BadHighSign", 0, 50);
			LOG_FAIL("No exception thrown");
			std::cout << f << std::endl;
		}
		catch (Form::GradeTooHighException& e) { LOG_OK(e.what()); }
		catch (std::exception& e) { LOG_FAIL(std::string("Wrong: ") + e.what()); }
	}

	LOG_TEST("Form sign_grade too low (3/8)");
	{
		try
		{
			Form f("BadLowSign", 151, 50);
			LOG_FAIL("No exception thrown");
		}
		catch (Form::GradeTooLowException& e) { LOG_OK(e.what()); }
		catch (std::exception& e) { LOG_FAIL(std::string("Wrong: ") + e.what()); }
	}

	LOG_TEST("Form exec_grade too high (4/8)");
	{
		try
		{
			Form f("BadHighExec", 50, 0);
			LOG_FAIL("No exception thrown");
		}
		catch (Form::GradeTooHighException& e) { LOG_OK(e.what()); }
		catch (std::exception& e) { LOG_FAIL(std::string("Wrong: ") + e.what()); }
	}

	LOG_TEST("Form exec_grade too low (5/8)");
	{
		try
		{
			Form f("BadLowExec", 50, 151);
			LOG_FAIL("No exception thrown");
		}
		catch (Form::GradeTooLowException& e) { LOG_OK(e.what()); }
		catch (std::exception& e) { LOG_FAIL(std::string("Wrong: ") + e.what()); }
	}

	LOG_TEST("Successful sign (6/8)");
	{
		try
		{
			Bureaucrat boss("Boss", 1);
			Form f("Important Form", 50, 25);
			std::cout << "Before: " << f << std::endl;
			boss.signForm(f);
			std::cout << "After:  " << f << std::endl;
			if (f.isSigned())
				LOG_OK("Form is signed");
			else
				LOG_FAIL("Form not signed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Failed sign — grade too low (7/8)");
	{
		try
		{
			Bureaucrat intern("Intern", 100);
			Form f("TopSecret", 10, 5);
			intern.signForm(f);
			if (!f.isSigned())
				LOG_OK("Form correctly NOT signed");
			else
				LOG_FAIL("Form should not be signed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Copy & assignment (8/8)");
	{
		try
		{
			Bureaucrat boss("Boss", 1);
			Form f("Original", 50, 50);
			boss.signForm(f);

			Form g(f);
			std::cout << "Copy: " << g << std::endl;

			Form h("Other", 100, 100);
			std::cout << "Before assign: " << h << std::endl;
			h = f;
			std::cout << "After assign:  " << h << std::endl;
			if (g.isSigned() && h.isSigned() && h.getName() == "Other")
				LOG_OK("Copy/assign behave correctly (name immutable, state copied)");
			else
				LOG_FAIL("Copy/assign incorrect");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
