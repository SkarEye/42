/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:32:25 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 16:37:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

#include "../include/Ansi.hpp"

#include <iostream>

AMateria::AMateria(void) : _type("default")
{
	LOG_DEBUG("[AMateria] default constructor called");
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	LOG_DEBUG("[AMateria] parameterized constructor called");
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	LOG_DEBUG("[AMateria] copy constructor called");
}

AMateria::~AMateria()
{
	LOG_DEBUG("[AMateria] destructor called");
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	LOG_DEBUG("[AMateria] copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses "
			  << this->_type
			  << " on "
			  << target.getName()
			  << " *"
			  << std::endl;
}