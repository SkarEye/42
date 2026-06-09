/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:31:34 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/20 18:39:34 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define ANSI_RESET	"\033[0m"
#define ANSI_BOLD	"\033[1m"
#define ANSI_CYAN	"\033[36m"
#define ANSI_GREEN	"\033[32m"
#define ANSI_RED	"\033[31m"
#define ANSI_YELLOW	"\033[33m"

#define LOG_INFO(x)	std::cout << ANSI_CYAN   << x << ANSI_RESET
#define LOG_TEST(x)	std::cout << std::endl << ANSI_YELLOW ANSI_BOLD << x <<  ANSI_RESET << std::endl
#define LOG_OK(x)	std::cout << ANSI_GREEN "[ OK ] " ANSI_RESET << x << std::endl
#define LOG_FAIL(x)	std::cout << ANSI_RED   "[FAIL] " ANSI_RESET << x << std::endl

int main()
{
	LOG_INFO("Starting test suite...\n");

	LOG_TEST("Default construction & full storage exception (1/14)");
	{
		try
		{
			Span a = Span();
			a.addNumber(1);
			LOG_FAIL("A number was added when the default size should be 0.");
		}
		catch (std::exception& e)
		{
			LOG_OK("Span threw: " << e.what());
		}
	}

	LOG_TEST("Parametric constructor accepts up to N numbers (2/14)");
	{
		try
		{
			Span a(5);
			a.addNumber(1);
			a.addNumber(2);
			a.addNumber(3);
			a.addNumber(4);
			a.addNumber(5);
			LOG_OK("Successfully added 5 numbers into a Span of size 5.");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("Exceeding capacity through addNumber throws (3/14)");
	{
		try
		{
			Span a(3);
			a.addNumber(10);
			a.addNumber(20);
			a.addNumber(30);
			a.addNumber(40);
			LOG_FAIL("A 4th element was added into a Span of size 3.");
		}
		catch (std::exception& e)
		{
			LOG_OK("Span threw: " << e.what());
		}
	}

	LOG_TEST("shortestSpan / longestSpan on subject example (4/14)");
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			unsigned int s = sp.shortestSpan();
			unsigned int l = sp.longestSpan();
			if (s == 2 && l == 14)
				LOG_OK("shortestSpan=" << s << " longestSpan=" << l << " (expected 2 / 14)");
			else
				LOG_FAIL("shortestSpan=" << s << " longestSpan=" << l << " (expected 2 / 14)");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("shortestSpan with 0 elements throws (5/14)");
	{
		try
		{
			Span a(10);
			a.shortestSpan();
			LOG_FAIL("shortestSpan returned a value on an empty Span.");
		}
		catch (std::exception& e)
		{
			LOG_OK("Span threw: " << e.what());
		}
	}

	LOG_TEST("longestSpan with 1 element throws (6/14)");
	{
		try
		{
			Span a(10);
			a.addNumber(42);
			a.longestSpan();
			LOG_FAIL("longestSpan returned a value on a single-element Span.");
		}
		catch (std::exception& e)
		{
			LOG_OK("Span threw: " << e.what());
		}
	}

	LOG_TEST("addRange from std::vector iterators (7/14)");
	{
		try
		{
			std::vector<int> v;
			v.push_back(100);
			v.push_back(200);
			v.push_back(150);
			v.push_back(175);

			Span a(10);
			a.addRange(v.begin(), v.end());
			unsigned int s = a.shortestSpan();
			unsigned int l = a.longestSpan();
			if (s == 25 && l == 100)
				LOG_OK("shortestSpan=" << s << " longestSpan=" << l << " (expected 25 / 100)");
			else
				LOG_FAIL("shortestSpan=" << s << " longestSpan=" << l << " (expected 25 / 100)");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("addRange from std::list iterators (8/14)");
	{
		try
		{
			std::list<int> l;
			l.push_back(-5);
			l.push_back(0);
			l.push_back(5);

			Span a(5);
			a.addRange(l.begin(), l.end());
			unsigned int s = a.shortestSpan();
			unsigned int lo = a.longestSpan();
			if (s == 5 && lo == 10)
				LOG_OK("shortestSpan=" << s << " longestSpan=" << lo << " (expected 5 / 10)");
			else
				LOG_FAIL("shortestSpan=" << s << " longestSpan=" << lo << " (expected 5 / 10)");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("addRange exceeding capacity throws (9/14)");
	{
		try
		{
			std::deque<int> d;
			for (int i = 0; i < 10; ++i)
				d.push_back(i);

			Span a(5);
			a.addRange(d.begin(), d.end());
			LOG_FAIL("addRange of 10 elements succeeded on a Span of size 5.");
		}
		catch (std::exception& e)
		{
			LOG_OK("Span threw: " << e.what());
		}
	}

	LOG_TEST("Mixing addNumber and addRange respects total capacity (10/14)");
	{
		try
		{
			std::vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);

			Span a(4);
			a.addNumber(10);
			a.addRange(v.begin(), v.end());
			LOG_OK("Filled Span(4) with 1 addNumber + 3 from addRange.");

			try
			{
				a.addNumber(99);
				LOG_FAIL("A 5th element was added into a Span of size 4.");
			}
			catch (std::exception& e)
			{
				LOG_OK("Further addNumber threw as expected: " << e.what());
			}
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("Copy constructor & assignment operator (11/14)");
	{
		try
		{
			Span a(5);
			a.addNumber(1);
			a.addNumber(8);
			a.addNumber(3);

			Span b(a);
			Span c;
			c = a;

			if (b.longestSpan() == 7 && c.longestSpan() == 7
				&& b.shortestSpan() == 2 && c.shortestSpan() == 2)
				LOG_OK("Copy and assignment produced identical spans.");
			else
				LOG_FAIL("Copy or assignment produced diverging spans.");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("Large Span (10,000 random numbers) (12/14)");
	{
		try
		{
			const unsigned int N = 10000;
			std::vector<int> v;
			v.reserve(N);
			std::srand(static_cast<unsigned int>(std::time(NULL)));
			for (unsigned int i = 0; i < N; ++i)
				v.push_back(std::rand());

			Span a(N);
			a.addRange(v.begin(), v.end());
			unsigned int s = a.shortestSpan();
			unsigned int l = a.longestSpan();
			LOG_OK("10,000 numbers -> shortestSpan=" << s << " longestSpan=" << l);
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("Very large Span (100,000 numbers, performance check) (13/14)");
	{
		try
		{
			const unsigned int N = 100000;
			std::vector<int> v;
			v.reserve(N);
			for (unsigned int i = 0; i < N; ++i)
				v.push_back(static_cast<int>(i) * 3 - 12345);

			Span a(N);
			a.addRange(v.begin(), v.end());
			unsigned int s = a.shortestSpan();
			unsigned int l = a.longestSpan();
			if (s == 3 && l == (N - 1) * 3)
				LOG_OK("100,000 numbers -> shortestSpan=" << s << " longestSpan=" << l);
			else
				LOG_FAIL("Unexpected spans: shortest=" << s << " longest=" << l);
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	LOG_TEST("Duplicates yield a shortestSpan of 0 (14/14)");
	{
		try
		{
			Span a(4);
			a.addNumber(7);
			a.addNumber(42);
			a.addNumber(7);
			a.addNumber(100);
			unsigned int s = a.shortestSpan();
			if (s == 0)
				LOG_OK("shortestSpan with duplicates = 0 as expected.");
			else
				LOG_FAIL("shortestSpan with duplicates = " << s << " (expected 0).");
		}
		catch (std::exception& e)
		{
			LOG_FAIL("Unexpected throw: " << e.what());
		}
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}