/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:16:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 17:23:36 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
