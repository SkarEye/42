/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:55:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 14:38:51 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define ANSI_RESET	"\033[0m"
#define ANSI_BOLD	"\033[1m"
#define ANSI_CYAN	"\033[36m"
#define ANSI_GREEN	"\033[32m"
#define ANSI_RED	"\033[31m"
#define ANSI_YELLOW	"\033[33m"

#define LOG_INFO(x)	std::cout << ANSI_CYAN   << x << ANSI_RESET
#define LOG_TEST(x)	std::cout << ANSI_YELLOW << ANSI_BOLD << "\n--- " << x << " ---" << ANSI_RESET << std::endl
#define LOG_OK(x)	std::cout << ANSI_GREEN  << "[ OK ] " << ANSI_RESET << x << std::endl
#define LOG_FAIL(x)	std::cout << ANSI_RED    << "[FAIL] " << ANSI_RESET << x << std::endl

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	LOG_INFO("Starting test suite...\n");

	LOG_TEST("Concrete form construction (1/9)");
	{
		try
		{
			ShrubberyCreationForm	s("mars");
			RobotomyRequestForm		r("Bender");
			PresidentialPardonForm	p("Richard M. Nixon");
			std::cout << s << std::endl;
			std::cout << r << std::endl;
			std::cout << p << std::endl;
			LOG_OK("All three forms constructed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Execute unsigned form throws (2/9)");
	{
		try
		{
			Bureaucrat				boss("Boss", 1);
			ShrubberyCreationForm	s("garden");
			boss.executeForm(s);
			if (!s.isSigned())
				LOG_OK("Form correctly NOT executed (unsigned)");
			else
				LOG_FAIL("Should have failed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Sign with too-low grade (3/9)");
	{
		try
		{
			Bureaucrat				intern("Intern", 150);
			PresidentialPardonForm	p("Zaphod");
			intern.signForm(p);
			if (!p.isSigned())
				LOG_OK("Correctly NOT signed");
			else
				LOG_FAIL("Should NOT have signed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Execute with too-low grade (4/9)");
	{
		try
		{
			Bureaucrat				boss("Boss", 1);
			Bureaucrat				low("LowGuy", 50);
			PresidentialPardonForm	p("Ford Prefect");
			boss.signForm(p);
			low.executeForm(p);
			LOG_OK("Executed (or failed with message)");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("ShrubberyCreationForm full flow (5/9)");
	{
		try
		{
			Bureaucrat				boss("Boss", 1);
			ShrubberyCreationForm	s("home");
			boss.signForm(s);
			boss.executeForm(s);
			LOG_OK("Check ./home_shrubbery for ASCII trees");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("RobotomyRequestForm full flow (6/9)");
	{
		try
		{
			Bureaucrat			boss("Boss", 1);
			RobotomyRequestForm	r("Marvin");
			boss.signForm(r);
			for (int i = 0; i < 5; ++i)
				boss.executeForm(r);
			LOG_OK("Robotomy attempts done");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("PresidentialPardonForm full flow (7/9)");
	{
		try
		{
			Bureaucrat				boss("Boss", 1);
			PresidentialPardonForm	p("Arthur Dent");
			boss.signForm(p);
			boss.executeForm(p);
			LOG_OK("Pardon executed");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}
	
	LOG_TEST("Polymorphism via AForm& (8/9)");
	{
		try
		{
			Bureaucrat 				boss("Boss", 1);
			ShrubberyCreationForm	s("polyTree");
			RobotomyRequestForm		r("polyBot");
			PresidentialPardonForm	p("polyTarget");

			AForm* forms[3] = { &s, &r, &p };
			for (int i = 0; i < 3; ++i)
			{
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
			}
			LOG_OK("Polymorphic dispatch works");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	LOG_TEST("Idempotency: sign/execute twice (9/9)");
	{
		try
		{
			Bureaucrat			boss("Boss", 1);
			RobotomyRequestForm	r("twice");
			boss.signForm(r);
			boss.signForm(r);
			boss.executeForm(r);
			boss.executeForm(r);
			LOG_OK("Repeated calls handled gracefully");
		}
		catch (std::exception& e) { LOG_FAIL(e.what()); }
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
