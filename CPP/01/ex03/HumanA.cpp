/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:29:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:02:30 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
	: name(name), weapon(weapon)
{
}

void	HumanA::attack(void)
{
	std::cout	<< name
				<< " attacks with their "
				<< weapon.getType()
				<< std::endl;
}
