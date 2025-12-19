/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:52:03 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 15:38:56 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed(void) : _n(0)
{
	LOG_DEBUG("[Fixed] Default constructor called");
}

Fixed::Fixed(const int n) : _n(n << _fPoint)
{
	LOG_DEBUG("[Fixed] Parameterized constructor called (int)");
}

Fixed::Fixed(const float f) : _n(std::roundf(f * (1 << _fPoint)))
{
	LOG_DEBUG("[Fixed] Parameterized constructor called (float)");
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

float	Fixed::toFloat(void) const
{
	return ((float)_n / (1 << _fPoint));
}

int	Fixed::toInt(void) const
{
	return (_n >> _fPoint);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}