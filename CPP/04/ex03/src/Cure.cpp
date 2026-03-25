/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:37:00 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 16:58:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Cure.hpp"

#include "../include/Ansi.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
	LOG_DEBUG("[Cure] default constructor called");
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	LOG_DEBUG("[Cure] copy constructor called");
}

Cure::~Cure()
{
	LOG_DEBUG("[Cure] destructor called");
}

Cure& Cure::operator=(const Cure& other)
{
	LOG_DEBUG("[Cure] copy assignment operator called");
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "
	<< target.getName()
	<< "'s wounds *"
	<< std::endl;
}
