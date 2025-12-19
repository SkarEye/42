/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:35:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/09 16:25:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	Harl 		harl;
	std::string	level = argv[1];
	std::string	levels[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"UNKNOWN"
	};
	int			i = 0;

	while (i < 4 && level != levels[i])
		i++;
	switch (i)
	{
		case 0:
			harl.complain(levels[0]);
		case 1:
			harl.complain(levels[1]);
		case 2:
			harl.complain(levels[2]);
		case 3:
			harl.complain(levels[3]);
			break;
		default:
			harl.complain(levels[4]);
	}
	return (0);
}
