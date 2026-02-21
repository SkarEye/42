/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:58:31 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/21 12:43:02 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "Point.hpp"

void	printTriangle(Point const a, Point const b, Point const c, Point const point);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#define ANSI_RED		"\033[31m"
#define ANSI_BRED		"\033[91m"

#define ANSI_GREEN		"\033[32m"
#define ANSI_BGREEN		"\033[92m"

#define ANSI_CYAN		"\033[36m"
#define ANSI_BCYAN		"\033[96m"

#define ANSI_BOLD		"\033[1m"
#define ANSI_RESET		"\033[0m"

#ifndef SILENT
# define LOG_SUCCESS(x) \
	do { \
		std::cout	<< ANSI_BGREEN << ANSI_BOLD \
					<< "[SUCCESS] " \
					<< ANSI_RESET << ANSI_GREEN \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# define LOG_ERROR(x) \
	do { \
		std::cout	<< ANSI_BRED << ANSI_BOLD \
					<< "[ERROR] " \
					<< ANSI_RESET << ANSI_RED \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# define LOG_INFO(x) \
	do { \
		std::cout	<< ANSI_BCYAN << ANSI_BOLD \
					<< "[INFO] " \
					<< ANSI_RESET << ANSI_CYAN \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# else
#  define LOG_SUCCESS(x) do {} while (0)
#  define LOG_ERROR(x) do {} while (0)
#  define LOG_INFO(x) do {} while (0)
#endif

static bool string_to_float(const std::string &s, float &out)
{
	std::stringstream ss(s);

	ss >> out;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 9)
	{
		LOG_ERROR("This test needs as parameters 4 pairs of Fixed values. Usage ./Fixed <a_x> <a_y> <b_x> <b_y> <c_x> <c_y> <p_x> <p_y>");
		return (1);
	}
	
	float	a_x, a_y, b_x, b_y, c_x, c_y, p_x, p_y;

		if (!string_to_float(argv[1], a_x) || !string_to_float(argv[2], a_y)
		|| !string_to_float(argv[3], b_x) || !string_to_float(argv[4], b_y)
		|| !string_to_float(argv[5], c_x) || !string_to_float(argv[6], c_y)
		|| !string_to_float(argv[7], p_x) || !string_to_float(argv[8], p_y))
		{
			LOG_ERROR("Could not successfully convert one or more given arguments into floats");
			return (1);
		}

	Point	a(a_x, a_y),
			b(b_x, b_y),
			c(c_x, c_y),
			p(p_x, p_y);

	printf("Initial values are : a_x : %f, a_y : %f, b_x : %f, b_y : %f, c_x : %f, c_y : %f, p_x : %f, p_y : %f.\n", a.x().toFloat(), a.y().toFloat(), b.x().toFloat(), b.y().toFloat(), c.x().toFloat(), c.y().toFloat(), p.x().toFloat(), p.y().toFloat());


	LOG_INFO("Printing triangle...");
	printTriangle(a, b, c, p);
	
	if (bsp(a, b, c, p))
		std::cout << "Given point is in triangle." << '\n';
	else
	 	std::cout << "Given point is not in triangle" << '\n';

	LOG_SUCCESS("Test completed");
	
	return (0);
}