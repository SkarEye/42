/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 15:03:11 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Ansi.hpp"

Cat::Cat(void)
{
	LOG_DEBUG("[Cat] Default constructor called");
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	LOG_DEBUG("[Cat] Copy constructor called");
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	LOG_DEBUG("[Cat] Destructor called");
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	LOG_DEBUG("[Cat] Copy assignment operator called");
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout	<< ANSI_YELLOW << ANSI_ITALIC
				<< "Purrr..."
				<< ANSI_RESET
				<< '\n';
}

void	Cat::setIdea(int const index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int const index) const
{
	return (this->_brain->getIdea(index));
}
