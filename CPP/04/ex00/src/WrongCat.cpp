/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 18:42:49 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Ansi.hpp"

WrongCat::WrongCat(void)
{
	LOG_DEBUG("[WrongCat] Default constructor called");
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	LOG_DEBUG("[WrongCat] Copy constructor called");
}

WrongCat::~WrongCat()
{
	LOG_DEBUG("[WrongCat] Destructor called");
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	LOG_DEBUG("[WrongCat] Copy assignment operator called");
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout	<< ANSI_YELLOW << ANSI_ITALIC << ANSI_BOLD
				<< "Moo...?"
				<< ANSI_RESET
				<< '\n';
}
