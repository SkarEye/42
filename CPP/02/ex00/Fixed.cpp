/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:52:03 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 14:31:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	LOG_DEBUG("[Fixed] Default constructor called");
}

Fixed::Fixed(const Fixed &other) : _n(other._n)
{
	LOG_DEBUG("[Fixed] Copy constructor called");
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_n = other._n;
	LOG_DEBUG("[Fixed] Assignment operator called");
	return (*this);
}

Fixed::~Fixed()
{
	LOG_DEBUG("[Fixed] Destructor called");
}

int	Fixed::getRawBits(void) const
{
	LOG_DEBUG("[Fixed] 'getRawBits' member function called");
	return (_n);
}

void	Fixed::setRawBits(const int raw)
{
	LOG_DEBUG("[Fixed] 'setRawBits' member function called");
	_n = raw;
}
