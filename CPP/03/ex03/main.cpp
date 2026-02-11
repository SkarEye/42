/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/24 10:15:59 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a;
	DiamondTrap	b("RubyClap");

	a.whoAmI();
	b.whoAmI();
	for (int i = 0; i < 49; i++)
		a.highFivesGuys();
	a.attack("something");
	a.attack("something else");
	b.takeDamage(1000);
	b.takeDamage(1);
	b.attack("anything else");

	a.whoAmI();
	b.whoAmI();

	DiamondTrap c(a);
	DiamondTrap d = a;

	c.whoAmI();
	d.whoAmI();

	d = b;

	d.whoAmI();
	
	return (0);
}
