/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 18:42:47 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Ansi.hpp"

Dog::Dog(void)
{
	LOG_DEBUG("[Dog] Default constructor called");
	this->_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	LOG_DEBUG("[Dog] Copy constructor called");
}

Dog::~Dog()
{
	LOG_DEBUG("[Dog] Destructor called");
}

Dog&	Dog::operator=(const Dog& other)
{
	LOG_DEBUG("[Dog] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout	<< ANSI_YELLOW << ANSI_ITALIC
				<< "Awoof!"
				<< ANSI_RESET
				<< '\n';
}
