/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:02:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:20:49 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
#include <iostream>

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


class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();

		std::string	getType(void) const;
		void		setType(std::string);
};

#endif
