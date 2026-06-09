/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:18:16 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 16:41:06 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"

#define ANSI_RESET	"\033[0m"
#define ANSI_BOLD	"\033[1m"
#define ANSI_CYAN	"\033[36m"
#define ANSI_GREEN	"\033[32m"
#define ANSI_RED	"\033[31m"
#define ANSI_YELLOW	"\033[33m"

#define LOG_INFO(x)	std::cout << ANSI_CYAN   << x << ANSI_RESET
#define LOG_TEST(x)	std::cout << ANSI_YELLOW << ANSI_BOLD << "\n--- " << x << " ---" << ANSI_RESET << std::endl

/* ------------------------------------------------------------------ */
/* Non-template callbacks (regular functions)                         */
/* ------------------------------------------------------------------ */

/* Read-only callback: takes its argument by const reference.         */
void	printInt(const int& x)
{
	std::cout << x << " ";
}

/* Mutating callback: takes its argument by non-const reference.      */
void	doubleInt(int& x)
{
	x *= 2;
}

/* ------------------------------------------------------------------ */
/* Template callbacks (instantiated by iter)                          */
/* ------------------------------------------------------------------ */

/* Read-only generic printer (works for any printable T).             */
template <typename T>
void	print(const T& x)
{
	std::cout << x << " ";
}

/* Mutating generic callback: appends "!" to a T that supports +=.    */
template <typename T>
void	shout(T& x)
{
	x += "!";
}

int	main(void)
{

	int			ints[] = {1, 2, 3, 4, 5};
	size_t		intsLen = sizeof(ints) / sizeof(ints[0]);

	std::string	words[] = {"hello", "template", "world"};
	size_t		wordsLen = sizeof(words) / sizeof(words[0]);

	double		doubles[] = {1.1, 2.2, 3.3, 4.4};
	size_t		doublesLen = sizeof(doubles) / sizeof(doubles[0]);

	char		chars[] = {'4', '2', '!'};
	size_t		charsLen = sizeof(chars) / sizeof(chars[0]);

	int	dummy[1] = {42}; /* C++98 forbids zero-sized arrays */

	LOG_INFO("Starting test suite...\n");

	LOG_TEST("int[] + printInt(const int&) (1/8)");
	{
		iter(ints, intsLen, printInt);
	}

	LOG_TEST("int[] + doubleInt(int&) then reprint (2/8)");
	{
		iter(ints, intsLen, doubleInt);
		iter(ints, intsLen, printInt);
	}

	LOG_TEST("int[] + print<int> (instantiated template) (3/8)");
	{
		iter(ints, intsLen, print<int>);
	}

	LOG_TEST("std::string[] + print<std::string> (4/8)");
	{
	iter(words, wordsLen, print<std::string>);
	}

	LOG_TEST("std::string[] + shout<std::string> then reprint (5/8)");
	{
		iter(words, wordsLen, shout<std::string>);
		iter(words, wordsLen, print<std::string>);
	}

	LOG_TEST("double[] + print<double> (6/8)");
	{
		iter(doubles, doublesLen, print<double>);
	}

	LOG_TEST("char[] + print<char> (7/8)");
	{
		iter(chars, charsLen, print<char>);
	}

	LOG_TEST("Empty range (len = 0) (8/8)");
	{
		iter(dummy, 0u, printInt);
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
