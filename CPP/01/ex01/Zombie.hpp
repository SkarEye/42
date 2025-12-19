/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 21:06:31 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

# define ANSI_RED		"\033[31m"
# define ANSI_BRED		"\033[91m"

# define ANSI_GREEN		"\033[32m"
# define ANSI_BGREEN	"\033[92m"

# define ANSI_YELLOW	"\033[33m"
# define ANSI_BYELLOW	"\033[93m"

#define ANSI_CYAN		"\033[36m"
#define ANSI_BCYAN		"\033[96m"

#define ANSI_PURPLE		"\033[35m"
#define ANSI_BPURPLE	"\033[95m"

#define ANSI_BOLD		"\033[1m"
#define ANSI_RESET		"\033[0m"

# ifdef DEBUG
#  define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BPURPLE << ANSI_BOLD \
					<< "[DEBUG] " \
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


class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();

		void	setName(std::string name);
		void	announce() const;
};

#endif 