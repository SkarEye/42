/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:52:03 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 21:01:45 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed(void) : _n(0) {}

Fixed::Fixed(const int n) : _n(n << _fPoint) {}

Fixed::Fixed(const float f) : _n(std::roundf(f * (1 << _fPoint))) {}

Fixed::Fixed(const Fixed& other) : _n(other._n) {}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_n = other._n;
	return (*this);
}

Fixed::~Fixed() {}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(const int raw)
{
	this->_n = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_n / (1 << _fPoint));
}

int	Fixed::toInt(void) const
{
	return (this->_n >> _fPoint);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_n > other._n);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_n < other._n);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_n >= other._n);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_n <= other._n);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_n == other._n);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_n != other._n);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result._n = this->_n + other._n;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result._n = this->_n - other._n;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	result._n = (this->_n * other._n) >> this->_fPoint;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	result._n = (this->_n / other._n) << this->_fPoint;
	return (result);
}

Fixed&	Fixed::operator-(void)
{
	this->_n = -this->_n;
	return (*this);
}

Fixed&	Fixed::operator+(void)
{
	return (*this);
}


Fixed&	Fixed::operator++(void)
{
	++this->_n;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--this->_n;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed copy = *this;

	++this->_n;
	return (copy);
}

Fixed	Fixed::operator--(int)
{
	Fixed copy = *this;

	--this->_n;
	return (copy);
}

Fixed	Fixed::abs(void) const
{
	Fixed	result;

	result.setRawBits(_n < 0 ? -_n : _n);
	return (result);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a._n > b._n)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._n > b._n)
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a._n > b._n)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._n > b._n)
		return (a);
	return (b);
}
