/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:04:54 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/24 10:26:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

#define ANSI_RED			"\033[31m"
#define ANSI_CLAPTRAP		ANSI_BOLD << "\033[38;5;208m"
#define ANSI_DIAMONDTRAP	ANSI_BOLD << "\033[36m"

DiamondTrap::DiamondTrap(void) :
	ClapTrap("DiamondTrap_clap_name"),
	ScavTrap(),
	FragTrap(),
	_name("DiamondTrap")
{
	LOG_DEBUG("[DiamondTrap] Default constructor called");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	LOG_DEBUG("[DiamondTrap] Parameterized constructor called");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	LOG_DEBUG("[DiamondTrap] Copy constructor called");
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	LOG_DEBUG("[DiamondTrap] Assignment operator called");
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	LOG_DEBUG("[DiamondTrap] Destructor called");

}
void	DiamondTrap::whoAmI(void) const
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "DiamondTrap "
					<< ANSI_DIAMONDTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " cannot identify itself, it is kaput !"
					<< ANSI_RESET
					<< '\n';
	}
	else
	{
		std::cout	<< "I am DiamondTrap "
					<< ANSI_DIAMONDTRAP
					<< this->_name
					<< ANSI_RESET
					<< ", but the basic ClapTraps call me "
					<< ANSI_CLAPTRAP
					<< this->ClapTrap::_name
					<< ANSI_RESET
					<< " !"
					<< '\n';
	}
}
