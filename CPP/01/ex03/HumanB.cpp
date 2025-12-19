/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:29:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:02:16 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), weapon(NULL)
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
	{
		std::cout	<< name
					<< " attacks with their "
					<< weapon->getType()
					<< std::endl;
	}
	else
	{
		std::cout	<< name
					<< " flails thier arms aimlessly"
					<< std::endl;
	}
}
