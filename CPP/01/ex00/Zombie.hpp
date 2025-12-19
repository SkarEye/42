/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 10:30:53 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
# include <string>

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
#  define LOG_INFO(x) do {} while (0)
# endif

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(std::string name);
		~Zombie();
		void announce() const;
};

#endif 