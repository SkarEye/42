/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:11:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 10:29:11 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	LOG_DEBUG("[Zombie] constructor called for " << name);
}

Zombie::~Zombie(void)
{
	LOG_DEBUG("[Zombie] destructor called for " << name);
}

void	Zombie::announce(void) const
{
	std::cout	<< name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
