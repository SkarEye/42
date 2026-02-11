/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:15:22 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 14:29:45 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Ansi.hpp"

Animal::Animal(void) : _type("Animal")
{
	LOG_DEBUG("[Animal] Default constructor called");
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	LOG_DEBUG("[Animal] Copy constructor called");
}

Animal::~Animal()
{
	LOG_DEBUG("[Animal] Destructor called");
}

Animal&	Animal::operator=(const Animal& other)
{
	LOG_DEBUG("[Animal] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout	<< ANSI_BLACK << ANSI_ITALIC
				<< "* indecipherable zoo noises *"
				<< ANSI_RESET
				<< '\n';
}
