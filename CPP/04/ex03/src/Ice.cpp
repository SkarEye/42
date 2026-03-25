/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:36:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 16:58:38 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"

#include "../include/Ansi.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice")
{
	LOG_DEBUG("[Ice] default constructor called");
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	LOG_DEBUG("[Ice] copy constructor called");
}

Ice::~Ice()
{
	LOG_DEBUG("[Ice] destructor called");
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName()
			  << " *"
			  << std::endl;
}
