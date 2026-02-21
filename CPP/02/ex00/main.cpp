/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:29:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/21 12:35:33 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "Fixed.hpp"

static bool	string_to_int(const std::string &s, int &out)
{
	std::stringstream	ss(s);

	ss >> out;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	int	status = 0;
	
	LOG_INFO("Starting round of tests (1/2)...");
	{
		Fixed	a;
		Fixed	b(a);
		Fixed	c;
		
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		
		LOG_SUCCESS("First round completed");
	}
	LOG_INFO("Starting round of tests (2/2)...");
	{
		int		n;

		if (argc != 2)
		{
			LOG_ERROR("This test needs as parameter a valid integer. Usage ./Fixed <n>");
			status |= 1;
		}
		else if (!string_to_int(argv[1], n))
		{
			LOG_ERROR("Could not successfully convert given argument into an integer");
			status |= 1;
		}
		else
		{
			LOG_INFO("Testing constructors:");
			Fixed	a;
			Fixed	b(a);
		
			std::cout << a.getRawBits() << std::endl;
			std::cout << b.getRawBits() << std::endl;

			LOG_INFO("Testing class variable manipulation:");

			a.setRawBits(n);
			b.setRawBits(a.getRawBits());


			std::cout << a.getRawBits() << std::endl;
			std::cout << b.getRawBits() << std::endl;
			
			LOG_SUCCESS("Second round completed");
		}
	}
	return (status);
}
