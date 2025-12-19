/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 13:48:11 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("tRAPcLAP");

	a.attack("a tree");
	b.attack("a 'Handsome Jack' poster");

	a.takeDamage(9);
	b.takeDamage(10);

	a.beRepaired(9);
	b.beRepaired(10);

	for (int i = 0; i < 7; i++)
		a.attack("nothing");
	a.attack("something");
	a.attack("something else");
	a.takeDamage(25);
	a.takeDamage(1);
	a.attack("anything else");

	ClapTrap c(a);
	ClapTrap d = b;

	c.attack("the air");
	d.attack("the ground");
	return (0);
}
