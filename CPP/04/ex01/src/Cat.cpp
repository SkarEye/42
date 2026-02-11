/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 19:17:13 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Ansi.hpp"

Cat::Cat(void)
{
	LOG_DEBUG("[Cat] Default constructor called");
	this->_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	LOG_DEBUG("[Cat] Copy constructor called");
}

Cat::~Cat()
{
	LOG_DEBUG("[Cat] Destructor called");
}

Cat&	Cat::operator=(const Cat& other)
{
	LOG_DEBUG("[Cat] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout	<< ANSI_YELLOW << ANSI_ITALIC
				<< "Purrr..."
				<< ANSI_RESET
				<< '\n';
}
