/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 13:48:05 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	FragTrap	b("BombClap");

	for (int i = 0; i < 99; i++)
		a.highFivesGuys();
	a.attack("something");
	a.attack("something else");
	a.takeDamage(1000);
	a.takeDamage(1);
	a.attack("anything else");

	FragTrap c(a);
	FragTrap d = a;

	c.highFivesGuys();
	d.highFivesGuys();

	d = b;

	d.highFivesGuys();
	
	return (0);
}
