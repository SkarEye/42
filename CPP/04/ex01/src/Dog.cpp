/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 11:43:14 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Ansi.hpp"

Dog::Dog(void)
{
	LOG_DEBUG("[Dog] Default constructor called");
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	LOG_DEBUG("[Dog] Copy constructor called");
}

Dog::~Dog()
{
	LOG_DEBUG("[Dog] Destructor called");
	delete this->_brain;
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

void	Dog::setIdea(int const index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int const index) const
{
	return (this->_brain->getIdea(index));
}
