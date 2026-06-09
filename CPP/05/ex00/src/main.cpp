/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:55:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/14 12:01:22 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

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

int	main(void)
{
	LOG_INFO("Starting test suite...\n\n");

	LOG_TEST("Valid construction test (1/7)");
	{
		try
		{
			Bureaucrat a("Michael", 1);
			Bureaucrat b("Ryan", 150);
			Bureaucrat c("Dwight", 75);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;
			LOG_OK("Constructed bureaucrats");
		}
		catch (std::exception& e)
		{	LOG_FAIL(e.what());}
	}

	LOG_TEST("GradeTooHigh at construction test (2/7)");
	{
	try
	{
		Bureaucrat a("TooHigh", 0);
		LOG_FAIL("No exception thrown");
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{	LOG_OK(e.what());}
	catch (std::exception& e) {
		LOG_FAIL(std::string("Wrong exception: ") + e.what());}
	}

	LOG_TEST("GradeTooLow at construction test (3/7)");
	{
	try
	{
		Bureaucrat a("TooLow", 151);
		LOG_FAIL("No exception thrown");
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{	LOG_OK(e.what());}
	catch (std::exception& e) {
		LOG_FAIL(std::string("Wrong exception: ") + e.what());}
	}

	LOG_TEST("GradeTooHigh at incrementGrade test (4/7)");
	{
		try
		{
			Bureaucrat a("Top", 1);
			a.incrementGrade();
			LOG_FAIL("No exception thrown");
			std::cout << a << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{	LOG_OK(e.what());}
		catch (std::exception& e)
		{	LOG_FAIL(std::string("Wrong exception: ") + e.what());}
	}

	LOG_TEST("GradeTooLow at decrementGrade test (5/7)");
	{
		try
		{
			Bureaucrat a("Bottom", 150);
			a.decrementGrade();
			LOG_FAIL("No exception thrown");
			std::cout << a << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{	LOG_OK(e.what());}
		catch (std::exception& e)
		{	LOG_FAIL(std::string("Wrong exception: ") + e.what());}
	}

	LOG_TEST("incrementGrade & decrementGrade test (6/7)");
	{
		try
		{
			Bureaucrat a("Jim", 2);
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << "after increment:\n" << a << std::endl;
			a.decrementGrade();
			a.decrementGrade();
			std::cout << "after 2 decrements:\n" << a << std::endl;
			LOG_OK("OK");
		}
		catch (std::exception& e)
		{	LOG_FAIL(e.what());}
	}

	LOG_TEST("Copy & assignment tests (7/7)");
	{
		try
		{
			Bureaucrat a("Original", 42);
			Bureaucrat b(a);
			Bureaucrat c("Other", 100);
			c = a;
			std::cout << "a: " << a << std::endl;
			std::cout << "b: " << b << std::endl;
			std::cout << "c: " << c << std::endl;
			LOG_OK("Names preserved, grades copied");
		}
		catch (std::exception& e)
		{	LOG_FAIL(e.what());}
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
