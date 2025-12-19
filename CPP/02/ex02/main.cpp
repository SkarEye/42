/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:29:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 21:11:45 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Fixed.hpp"

#define WRITE_BOOL(x) (x? "true" : "false")

int	main(int argc, char **argv)
{
	int	status = 0;
	
	LOG_INFO("Starting round of tests (1/2)...");
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		LOG_SUCCESS("First round completed");
	}
	{
		if (argc != 5)
		{
			LOG_ERROR("This test needs as parameters 2 valid integers and 2 valid floats respectively. Usage ./Fixed <n1> <n2> <f1> <f2>");
			status |= 1;
		}
		else
		{
			int			n1 = std::atoi(argv[1]);
			int			n2 = std::atoi(argv[2]);
			float		f1 = std::atof(argv[3]);
			float		f2 = std::atof(argv[4]);

			Fixed		a(n1);
			Fixed		b(n2);

			Fixed		c(f1);
			Fixed		d(f2);

			Fixed const e(n1);
			Fixed const f(f1);

			LOG_INFO("Set values for Fixed variables. After initiation:");
			
			std::cout << "a = " << a << std::endl;
			std::cout << "b = " << b << std::endl;
			std::cout << "c = " << c << std::endl;
			std::cout << "d = " << d << std::endl;
			std::cout << "e = " << e << std::endl;
			std::cout << "f = " << f << std::endl;

			LOG_INFO("Testing boolean operators:");

			std::cout << a << " < " << b << " is " << WRITE_BOOL(a < b) << std::endl;
			std::cout << a << " > " << b << " is " << WRITE_BOOL(a > b) << std::endl;
			std::cout << c << " <= " << d << " is " << WRITE_BOOL(c <= d) << std::endl;
			std::cout << c << " >= " << d << " is " << WRITE_BOOL(c >= d) << std::endl;
			std::cout << a << " == " << d << " is " << WRITE_BOOL(a == d) << std::endl;
			std::cout << b << " != " << c << " is " << WRITE_BOOL(b != c) << std::endl;

			LOG_INFO("Testing arithmetic operators:");

			std::cout << a << " + " << b << " = " << a + b << std::endl;
			std::cout << c << " - " << d << " = " << c - d << std::endl;
			std::cout << a << " / " << d << " = " << a / d << std::endl;
			std::cout << b << " * " << c << " = " << b * c << std::endl;
		
			LOG_INFO("Testing pre/post processors:");
		
			std::cout << "a = " << a << ", a++ = " << a++ << ", a = " << a << std::endl;
			std::cout << "a = " << a << ", a-- = " << a-- << ", a = " << a << std::endl;
			std::cout << "a = " << a << ", ++a = " << ++a << ", a = " << a << std::endl;
			std::cout << "a = " << a << ", --a = " << --a << ", a = " << a << std::endl;

			LOG_INFO("Testing max and min functions:");

			std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;
			std::cout << "min(" << c << ", " << d << ") = " << Fixed::min(c, d) << std::endl;
			std::cout << "max(" << a << ", " << e << ") = " << Fixed::min(a, e) << std::endl;
			std::cout << "min(" << d << ", " << f << ") = " << Fixed::min(d, f) << std::endl;

			LOG_SUCCESS("Second round completed");
		}
	}
	return (status);
}
