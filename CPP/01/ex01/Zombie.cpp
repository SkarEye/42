/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:11:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 21:13:29 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	LOG_DEBUG("[Zombie] constructor called. No name given");
}

Zombie::Zombie(std::string name) : name(name)
{
	LOG_DEBUG("[Zombie] constructor called for " << name);
}

Zombie::~Zombie(void)
{
	LOG_DEBUG("[Zombie] destructor called for " << name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	LOG_DEBUG("[Zombie] set name to " << name);
}

void	Zombie::announce(void) const
{
	std::cout	<< name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
