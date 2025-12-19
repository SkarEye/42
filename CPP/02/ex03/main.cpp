/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:58:31 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 20:28:39 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

int	main(int argc, char **argv)
{
	if (argc != 9)
	{
		LOG_ERROR("This test needs as parameters 4 pairs of Fixed values. Usage ./Fixed <a_x> <a_y> <b_x> <b_y> <c_x> <c_y> <p_x> <p_y>");
		return (1);
	}
	Point	a(std::atoi(argv[1]), std::atoi(argv[2])),
			b(std::atoi(argv[3]), std::atoi(argv[4])),
			c(std::atoi(argv[5]), std::atoi(argv[6])),
			p(std::atoi(argv[7]), std::atoi(argv[8]));

	LOG_INFO("Printing triangle...");
	printTriangle(a, b, c, p);
	
	if (bsp(a, b, c, p))
		std::cout << "Given point is in triangle." << '\n';
	else
	 	std::cout << "Given point is not in triangle" << '\n';

	LOG_SUCCESS("Test completed");
	
	return (0);
}