/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:09:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/09 16:04:35 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

#define ANSI_BLACK		"\033[30m"
#define ANSI_BBLACK		"\033[90m"

#define ANSI_RED		"\033[31m"
#define ANSI_BRED		"\033[91m"

#define ANSI_YELLOW		"\033[33m"
#define ANSI_BYELLOW	"\033[93m"

#define ANSI_CYAN		"\033[36m"
#define ANSI_BCYAN		"\033[96m"

#define ANSI_PURPLE		"\033[35m"
#define ANSI_BPURPLE	"\033[95m"

#define ANSI_BOLD		"\033[1m"
#define ANSI_ITALIC		"\033[3m"
#define ANSI_RESET		"\033[0m"

static void	_noise(void)
{
	std::cout 	<< ANSI_BBLACK << ANSI_BOLD
				<< "[ STATIC ]" << '\n'
				<< ANSI_RESET << ANSI_BLACK << ANSI_ITALIC
				<< "..zzzZZZZZzzz..zZZZzz.." << '\n'
				<< ANSI_RESET;
}

void	Harl::debug(void)
{
	std::cout 	<< ANSI_BPURPLE << ANSI_BOLD
				<< "[ WARNING ]" << '\n'
				<< ANSI_RESET << ANSI_PURPLE
				<< "..zzzZZZZZzzz..Is this thing on ?..zzZZzzz..n you h..zzZz..r me?" << '\n'
				<< ANSI_RESET;
}

void	Harl::info(void)
{
	std::cout 	<< ANSI_BCYAN << ANSI_BOLD
				<< "[ INFO ]" << '\n'
				<< ANSI_RESET << ANSI_CYAN
				<< "..zZz..isten to me, I have some ..zZzzz..rmation re..zZZzzzZz.. Xa..zZzzz..iel." << '\n'
				<< ANSI_RESET;
}

void	Harl::warning(void)
{
	std::cout 	<< ANSI_BYELLOW << ANSI_BOLD
				<< "[ WARNING ]" << '\n'
				<< ANSI_RESET << ANSI_YELLOW
				<< "No ! Do NOT ..zZZZzzz..ccess, you would be ..zZZZzzz..sking everyTHI..ZZzzz.." << '\n'
				<< ANSI_RESET;
}

void	Harl::error(void)
{
	std::cout 	<< ANSI_BRED << ANSI_BOLD
				<< "[ ERROR ]" << '\n'
				<< ANSI_RESET << ANSI_RED
				<< ".zzZZZZzzzzZZzzzzZZZZZzzzz.. Run. ..zzzZZZzzzZzZZZzzzzzZZzz.." << '\n'
				<< ANSI_RESET;
}

void	Harl::complain(std::string& level)
{
	t_HarlFn levels[] =
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].name == level)
		{
			(this->*levels[i].func)();
			return ;
		}
	}
	_noise();
}
