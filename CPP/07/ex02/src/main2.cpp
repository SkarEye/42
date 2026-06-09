/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:46:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 21:19:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

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

template <typename T>
void	dump(const Array<T>& a)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << "] (size = " << a.size() << ")" << std::endl;
}

int	main(void)
{
	LOG_INFO("Starting test suite...\n");

	LOG_TEST("Default constructor -> empty array (1/9)");
	{
		Array<int>	empty;
		std::cout << "empty.size() = " << empty.size() << std::endl;
		if (empty.size() == 0)
			LOG_OK("empty array has size 0");
		else
			LOG_FAIL("empty array does not have size 0");
	}

	LOG_TEST("Size constructor -> default-initialized to 0 (2/9)");
	{
		Array<int>	a(5);
		dump(a);
		bool	allZero = true;
		for (unsigned int i = 0; i < a.size(); ++i)
			if (a[i] != 0)
				allZero = false;
		if (allZero && a.size() == 5)
			LOG_OK("all elements value-initialized to 0");
		else
			LOG_FAIL("elements not properly value-initialized");
	}

	LOG_TEST("Non-const operator[] writes through (3/9)");
	{
		Array<int>	a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i * 10);
		dump(a);
		if (a[3] == 30)
			LOG_OK("a[3] == 30");
		else
			LOG_FAIL("write through operator[] failed");
	}

	LOG_TEST("Copy constructor is a DEEP copy (4/9)");
	{
		Array<int>	a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i + 1);
		Array<int>	b(a);
		b[0] = 999;
		std::cout << "a: "; dump(a);
		std::cout << "b: "; dump(b);
		if (a[0] == 1 && b[0] == 999)
			LOG_OK("modifying the copy did not affect the original");
		else
			LOG_FAIL("shallow copy detected");
	}

	LOG_TEST("Assignment operator is a DEEP copy (5/9)");
	{
		Array<int>	a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i + 1);
		Array<int>	c;
		c = a;
		c[1] = -1;
		std::cout << "a: "; dump(a);
		std::cout << "c: "; dump(c);
		if (a[1] == 2 && c[1] == -1 && c.size() == 5)
			LOG_OK("assignment performs a deep copy and resizes");
		else
			LOG_FAIL("assignment did not deep-copy correctly");
	}

	LOG_TEST("Self-assignment is safe (6/9)");
	{
		Array<int>	a(3);
		a[0] = 7; a[1] = 8; a[2] = 9;
		Array<int> &copy = a;

		copy = a;

		dump(a);
		if (copy[0] == 7 && copy[1] == 8 && copy[2] == 9)
			LOG_OK("self-assignment preserved contents");
		else
			LOG_FAIL("self-assignment corrupted the array");
	}

	LOG_TEST("Out-of-bounds access throws std::exception (7/9)");
	{
		Array<int>	a(3);
		try
		{
			std::cout << a[42] << std::endl;
			LOG_FAIL("no exception was thrown");
		}
		catch (std::exception& e)
		{
			std::cout << "caught: " << e.what() << std::endl;
			LOG_OK("std::exception was thrown");
		}
		try
		{
			std::cout << a[a.size()] << std::endl;
			LOG_FAIL("a[size()] should have thrown");
		}
		catch (std::exception& e)
		{
			(void)e;
			LOG_OK("a[size()] correctly throws");
		}
	}

	LOG_TEST("Works with any T (std::string) (8/9)");
	{
		Array<std::string>	s(3);
		s[0] = "hello";
		s[1] = "template";
		s[2] = "array";
		dump(s);
		if (s[0] == "hello" && s[2] == "array")
			LOG_OK("Array<std::string> behaves correctly");
		else
			LOG_FAIL("Array<std::string> misbehaves");
	}

	LOG_TEST("const operator[] reads from const reference (9/9)");
	{
		Array<int>	a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i * 10);
		const Array<int>&	cref = a;
		std::cout << "cref[2] = " << cref[2] << std::endl;
		if (cref[2] == 20)
			LOG_OK("const operator[] returns the expected value");
		else
			LOG_FAIL("const operator[] returned the wrong value");

		/* const out-of-bounds also throws */
		try
		{
			std::cout << cref[100] << std::endl;
			LOG_FAIL("const out-of-bounds did not throw");
		}
		catch (std::exception& e)
		{
			(void)e;
			LOG_OK("const out-of-bounds throws");
		}
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
