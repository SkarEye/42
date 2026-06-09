/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:55:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 16:02:06 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

	LOG_TEST("Intern creates known forms (1/6)");
	{
		Intern		intern;
		const char*	names[3]   = { "shrubbery creation", "robotomy request", "presidential pardon" };
		const char*	targets[3] = { "garden",             "Bender",           "Arthur Dent" };

		for (int i = 0; i < 3; ++i)
		{
			AForm*	f = intern.makeForm(names[i], targets[i]);
			if (f)
			{
				std::cout << *f << std::endl;
				delete f;
				LOG_OK(names[i]);
			}
			else
				LOG_FAIL(names[i]);
		}
	}

	LOG_TEST("Unknown form name (2/6)");
	{
		Intern	intern;
		AForm*	f = intern.makeForm("coffee request", "espresso");
		if (f == NULL)
			LOG_OK("makeForm returned NULL as expected");
		else
		{
			LOG_FAIL("Expected NULL, got a form");
			delete f;
		}
	}

	LOG_TEST("Subject scenario (3/6)");
	{
		Intern	someRandomIntern;
		AForm*	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			Bureaucrat boss("Boss", 1);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
			LOG_OK("Subject scenario executed");
		}
		else
			LOG_FAIL("Failed to create RobotomyRequestForm");
	}

	LOG_TEST("Full sign/execute pipeline (4/6)");
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);

		const char* names[3]   = { "shrubbery creation", "robotomy request", "presidential pardon" };
		const char* targets[3] = { "home",               "Marvin",           "Ford Prefect" };

		for (int i = 0; i < 3; ++i)
		{
			AForm*	f = intern.makeForm(names[i], targets[i]);
			if (!f)
			{
				LOG_FAIL(names[i]);
				continue;
			}
			boss.signForm(*f);
			boss.executeForm(*f);
			delete f;
		}
		LOG_OK("Pipeline complete");
	}

	LOG_TEST("Low-grade bureaucrat fails (5/6)");
	{
		Intern		intern;
		Bureaucrat	low("42Stud", 150);
		AForm*		f = intern.makeForm("presidential pardon", "Zaphod");
		if (f)
		{
			low.signForm(*f);
			low.executeForm(*f);
			delete f;
			LOG_OK("Both operations correctly failed");
		}
		else
			LOG_FAIL("Could not create form");
	}

	LOG_TEST("Multiple unknown names (6/6)");
	{
		Intern		intern;
		const char*	bad[4] = { "", "ROBOTOMY REQUEST", "shrubbery", "robotomy_request" };
		bool all_null = true;
		for (int i = 0; i < 4; ++i)
		{
			AForm* f = intern.makeForm(bad[i], "x");
			if (f)
			{
				all_null = false;
				delete f;
			}
		}
		if (all_null)
			LOG_OK("All unknown names correctly returned NULL");
		else
			LOG_FAIL("Some unknown name produced a form");
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}