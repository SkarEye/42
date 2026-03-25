/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:36:47 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 18:33:01 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

#include "../include/Ansi.hpp"

Character::Character() : _name("unnamed"), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 1024; i++)
		this->_floor[i] = NULL;
}

Character::Character(std::string const & name) : _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 1024; i++)
		this->_floor[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _floorCount(other._floorCount)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 1024; i++)
		this->_floor[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0; i < this->_floorCount; i++)
	{
		if (this->_floor[i])
			delete this->_floor[i];
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		for (int i = 0; i < this->_floorCount; i++)
		{
			if (this->_floor[i])
				delete this->_floor[i];
		}
		for (int i = 0; i < 1024; i++)
			this->_floor[i] = NULL;
		this->_floorCount = 0;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		LOG_WARNING("Cannot equip nothing to " + this->_name + "'s inventory.\n");
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	LOG_WARNING("Inventory full, cannot equip " + m->getType() + " to " + this->_name + "'s inventory.\n");
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		LOG_WARNING("Invalid inventory index, cannot unequip materia to " + this->_name + "'s floor.\n");
		return ;
	}
	if (!this->_inventory[idx])
	{
		LOG_WARNING("No materia in inventory slot, cannot unequip materia to " + this->_name + "'s floor.\n");
		return ;
	}
	if (this->_floorCount >= 1024)
	{
		LOG_WARNING("Floor full, cannot unequip materia to " + this->_name + "'s floor.\n");
		return ;
	}
	this->_floor[this->_floorCount++] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		LOG_WARNING("Invalid inventory index, cannot use materia from " + this->_name + "'s inventory.\n");
		return ;
	}
	if (!this->_inventory[idx])
	{
		LOG_WARNING("No materia in inventory slot, cannot use materia from " + this->_name + "'s inventory.\n");
		return ;
	}
	this->_inventory[idx]->use(target);
}