/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:26:04 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/09 15:14:53 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
# define LOG_HPP

# include <string>
# include <iostream>

# define ANSI_RED		"\033[31m"
# define ANSI_BRED		"\033[91m"

# define ANSI_GREEN		"\033[32m"
# define ANSI_BGREEN	"\033[92m"

# define ANSI_YELLOW	"\033[33m"
# define ANSI_BYELLOW	"\033[93m"

# define ANSI_CYAN		"\033[36m"
# define ANSI_BCYAN		"\033[96m"

# define ANSI_PURPLE	"\033[35m"
# define ANSI_BPURPLE	"\033[95m"

# define ANSI_BOLD		"\033[1m"
# define ANSI_RESET		"\033[0m"

# ifdef DEBUG
#  define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BPURPLE << ANSI_BOLD \
					<< "[ DEBUG ] " \
					<< ANSI_RESET << ANSI_PURPLE \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
# else
#  define LOG_DEBUG(x) do {} while (0)
# endif

# ifndef SILENT
#  define LOG_SUCCESS(x) \
	do { \
		std::cout	<< ANSI_BGREEN << ANSI_BOLD \
					<< "[ SUCCESS ] " \
					<< ANSI_RESET << ANSI_GREEN \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_WARNING(x) \
	do { \
		std::cerr	<< ANSI_BYELLOW << ANSI_BOLD \
					<< "[ WARNING ] " \
					<< ANSI_RESET << ANSI_YELLOW \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_ERROR(x) \
	do { \
		std::cerr	<< ANSI_BRED << ANSI_BOLD \
					<< "[ ERROR ] " \
					<< ANSI_RESET << ANSI_RED \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_INFO(x) \
	do { \
		std::cout	<< ANSI_BCYAN << ANSI_BOLD \
					<< "[ INFO ] " \
					<< ANSI_RESET << ANSI_CYAN \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
# else
#  define LOG_SUCCESS(x) do {} while (0)
#  define LOG_WARNING(x) do {} while (0)
#  define LOG_ERROR(x) do {} while (0)
#  define LOG_INFO(x) do {} while (0)
# endif
#endif
