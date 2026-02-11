/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ansi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 19:16:23 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_HPP
# define ANSI_HPP

# include <string>
# include <iostream>

# define ANSI_RESET			"\033[0m\002"
# define ANSI_BOLD			"\033[1m\002"
# define ANSI_ITALIC		"\033[3m\002"
# define ANSI_UNDERLINE		"\033[4m\002"
# define ANSI_BLINK			"\033[5m\002"
# define ANSI_REVERSE		"\033[7m\002"
# define ANSI_HIDDEN		"\033[8m\002"
# define ANSI_STRIKETHROUGH	"\033[9m\002"

# define ANSI_BLACK			"\033[30m\002"
# define ANSI_RED			"\033[31m\002"
# define ANSI_GREEN			"\033[32m\002"
# define ANSI_YELLOW		"\033[33m\002"
# define ANSI_BLUE			"\033[34m\002"
# define ANSI_MAGENTA		"\033[35m\002"
# define ANSI_CYAN			"\033[36m\002"
# define ANSI_WHITE			"\033[37m\002"

# define ANSI_BBLACK		"\033[90m\002"
# define ANSI_BRED			"\033[91m\002"
# define ANSI_BGREEN		"\033[92m\002"
# define ANSI_BYELLOW		"\033[93m\002"
# define ANSI_BBLUE			"\033[94m\002"
# define ANSI_BMAGENTA		"\033[95m\002"
# define ANSI_BCYAN			"\033[96m\002"
# define ANSI_BWHITE		"\033[97m\002"

# define ANSI_BG_BLACK		"\033[40m\002"
# define ANSI_BG_RED		"\033[41m\002"
# define ANSI_BG_GREEN		"\033[42m\002"
# define ANSI_BG_YELLOW		"\033[43m\002"
# define ANSI_BG_BLUE		"\033[44m\002"
# define ANSI_BG_MAGENTA	"\033[45m\002"
# define ANSI_BG_CYAN		"\033[46m\002"
# define ANSI_BG_WHITE		"\033[47m\002"

# define ANSI_BBG_BLACK		"\033[100m\002"
# define ANSI_BBG_RED		"\033[101m\002"
# define ANSI_BBG_GREEN		"\033[102m\002"
# define ANSI_BBG_YELLOW	"\033[103m\002"
# define ANSI_BBG_BLUE		"\033[104m\002"
# define ANSI_BBG_MAGENTA	"\033[105m\002"
# define ANSI_BBG_CYAN		"\033[106m\002"
# define ANSI_BBG_WHITE		"\033[107m\002"

# ifdef DEBUG
#  define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BMAGENTA << ANSI_BOLD \
					<< "[DEBUG] " \
					<< ANSI_RESET << ANSI_MAGENTA \
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
					<< "[SUCCESS] " \
					<< ANSI_RESET << ANSI_GREEN \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_WARNING(x) \
	do { \
		std::cout	<< ANSI_BYELLOW << ANSI_BOLD \
					<< "[WARNING] " \
					<< ANSI_RESET << ANSI_YELLOW \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_ERROR(x) \
	do { \
		std::cout	<< ANSI_BRED << ANSI_BOLD \
					<< "[ERROR] " \
					<< ANSI_RESET << ANSI_RED \
					<< x \
					<< ANSI_RESET \
					<<std::endl; \
	} while (0)
#  define LOG_INFO(x) \
	do { \
		std::cout	<< ANSI_BCYAN << ANSI_BOLD \
					<< "[INFO] " \
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