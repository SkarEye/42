/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:09:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:21:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	LOG_DEBUG("[Weapon] constructor called for " << type);
}

Weapon::~Weapon(void)
{
	LOG_DEBUG("[Weapon] destructor called for " << type);
}

std::string	Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	LOG_DEBUG("[Weapon] name change for " << this->type << " to " << type);
	this->type = type;
}
