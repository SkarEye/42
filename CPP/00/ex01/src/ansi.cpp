/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:28:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 13:10:37 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/ansi.hpp"

void	print_message(const char *object, const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< object
				<< ": "
				<< ANSI_RESET
				<< message;
	if (newline)
		std::cout << std::endl;
}

void	print_warning(const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< ANSI_BYELLOW
				<< "WARNING: "
				<< ANSI_RESET
				<< ANSI_YELLOW
				<< message
				<< ANSI_RESET;
	if (newline)
		std::cout << std::endl;
}

void	print_error(const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< ANSI_BRED
				<< "ERROR: "
				<< ANSI_RESET
				<< ANSI_RED
				<< message
				<< ANSI_RESET;
	if (newline)
		std::cout << std::endl;
}

void	print_success(const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< ANSI_BGREEN
				<< "SUCCESS: "
				<< ANSI_RESET
				<< ANSI_GREEN
				<< message
				<< ANSI_RESET;
	if (newline)
		std::cout << std::endl;
}

void	print_info(const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< ANSI_BCYAN
				<< "INFO: "
				<< ANSI_RESET
				<< ANSI_CYAN
				<< message
				<< ANSI_RESET;
	if (newline)
		std::cout << std::endl;
}

void	print_debug(const char *message, bool newline)
{
	std::cout	<< ANSI_BOLD
				<< ANSI_BMAGENTA
				<< "DEBUG: "
				<< ANSI_RESET
				<< ANSI_MAGENTA
				<< message
				<< ANSI_RESET;
	if (newline)
		std::cout << std::endl;
}

void	print_nl(void)
{
	std::cout << std::endl;
}
