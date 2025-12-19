/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 13:48:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a;
	ScavTrap	b("tRAPsTIK");

	a.guardGate();
	b.guardGate();

	a.takeDamage(99);
	b.takeDamage(100);

	a.beRepaired(99);
	b.beRepaired(100);

	for (int i = 0; i < 47; i++)
		a.attack("nothing");
	a.attack("something");
	a.attack("something else");
	a.takeDamage(1000);
	a.takeDamage(1);
	a.attack("anything else");

	ScavTrap c(a);
	ScavTrap d = b;

	c.guardGate();
	d.guardGate();
	
	return (0);
}
