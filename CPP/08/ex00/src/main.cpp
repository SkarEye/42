/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:31:34 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/20 16:45:17 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
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
	
	std::vector<int> v;
	for (int i = 0; i < 5; ++i) v.push_back(i * 10);
	
	LOG_TEST("Valid integer search in vector (1/3)");
	{
		try
		{
			std::vector<int>::iterator it = easyfind(v, 30);
			LOG_OK("Found in vector: " << *it);
		}
		catch (std::exception& e)
		{
			LOG_FAIL("easyfind throwed: " << e.what());
		}
	}
	LOG_TEST("Invalid integer search in vector (2/3)");
	{
		try
		{
			std::vector<int>::iterator it = easyfind(v, 1);
			LOG_FAIL("Found in vector: " << *it);
		}
		catch (std::exception& e)
		{
			LOG_OK("easyfind throwed: " << e.what());
		}
	}

	std::list<int> l;
	l.push_back(1); l.push_back(2); l.push_back(3);

	LOG_TEST("Valid integer search in list (1/3)");
	{
		try
		{
			std::list<int>::iterator it = easyfind(l, 2);
			LOG_OK("Found in list: " << *it);
		}
		catch (std::exception& e)
		{
			LOG_FAIL("easyfind throwed: " << e.what());
		}
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}