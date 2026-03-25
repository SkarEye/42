/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:39:01 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 11:53:36 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Ansi.hpp"

Brain::Brain(void)
{
	LOG_DEBUG("[Brain] Default constructor called");
}

Brain::Brain(const Brain& other)
{
	LOG_DEBUG("[Brain] Copy constructor called");
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain::~Brain()
{
	LOG_DEBUG("[Brain] Destructor called");
}

Brain&	Brain::operator=(const Brain& other)
{
	LOG_DEBUG("[Brain] Copy assignment operator called");
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int const index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
	 	LOG_WARNING("[Brain] Index out of scope");
}

std::string	Brain::getIdea(int const index) const
{
	if (index >= 0 && index < 100)
	{
		if (this->_ideas[index].empty())
			LOG_WARNING("[Brain] Current brain doesn't have an idea to spare here !");
		return (this->_ideas[index]);
	}
	LOG_ERROR("[Brain] Index out of scope");
	return (std::string());
}
