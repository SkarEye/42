/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:15:22 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 14:29:45 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Ansi.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	LOG_DEBUG("[WrongAnimal] Default constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	LOG_DEBUG("[WrongAnimal] Copy constructor called");
}

WrongAnimal::~WrongAnimal()
{
	LOG_DEBUG("[WrongAnimal] Destructor called");
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	LOG_DEBUG("[WrongAnimal] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout	<< ANSI_BLACK << ANSI_ITALIC << ANSI_BOLD
				<< "* hellish screams, defiant of all known animal sounds *"
				<< ANSI_RESET
				<< '\n';
}
