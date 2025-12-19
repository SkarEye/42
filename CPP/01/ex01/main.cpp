/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:34:20 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 21:13:55 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(int argc, char **argv)
{
	int			N;
	std::string	name;
	Zombie		*horde;

	if (argc != 3)
	{
		LOG_ERROR("Execute program as such: [PROG_NAME] [Nb. ZOMBIES] [ZOMBIE_NAME]");
		return (1);
	}
	N = std::atoi(argv[1]);
	if (N < 0)
	{
		LOG_ERROR("Enter a valid positive value");
		return (1);
	}
	if (N == 0)
		LOG_WARNING("A horde with zero zombies won't make much noise...");
	name = argv[2];
	LOG_INFO("A horde is forming...");
	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	LOG_SUCCESS("Exiting program successfully...");
	return (0);
}
