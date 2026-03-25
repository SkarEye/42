/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:15:22 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 14:30:18 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Ansi.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	LOG_DEBUG("[Animal] Default constructor called");
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	LOG_DEBUG("[Animal] Copy constructor called");
}

AAnimal::~AAnimal()
{
	LOG_DEBUG("[Animal] Destructor called");
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	LOG_DEBUG("[AAnimal] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::makeSound() const
{
	std::cout	<< ANSI_BLACK << ANSI_ITALIC
				<< "* indecipherable zoo noises *"
				<< ANSI_RESET
				<< '\n';
}
