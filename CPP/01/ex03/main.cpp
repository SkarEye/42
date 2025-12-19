/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:41:50 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:14:03 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon	weapon = Weapon("rusty shield");
		HumanA	billy("Billy", weapon);
		HumanB	nathaniel("Nathaniel the Third, The Ravenous");
		billy.attack();
		nathaniel.attack();
		nathaniel.setWeapon(weapon);
		billy.attack();
		nathaniel.attack();
		weapon.setType("Bane of the Gods");
		billy.attack();
		nathaniel.attack();
	}
return (0);
}
