/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:52:03 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 20:17:55 by mattcarniel      ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed &other)
{
	LOG_DEBUG("[Fixed] Assignment operator called");
	if (this != &other)
		this->_n = other._n;
	return (*this);
}

Fixed::~Fixed()
{
	LOG_DEBUG("[Fixed] Destructor called");
}

int	Fixed::getRawBits(void) const
{
	LOG_DEBUG("[Fixed] 'getRawBits' member function called");
	return (this->_n);
}

void	Fixed::setRawBits(const int raw)
{
	LOG_DEBUG("[Fixed] 'setRawBits' member function called");
	this->_n = raw;
}

float	Fixed::toFloat(void) const
{
	LOG_DEBUG("[Fixed] 'toFloat' member function called");
	return ((float)_n / (1 << _fPoint));
}

int	Fixed::toInt(void) const
{
	LOG_DEBUG("[Fixed] 'toInt' member function called");
	return (this->_n >> _fPoint);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	LOG_DEBUG("[Fixed] '<<' overloaded operation called");
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '>' overloaded operation called");
	return (this->_n > other._n);
}

bool	Fixed::operator<(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '<' overloaded operation called");
	return (this->_n < other._n);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '>=' overloaded operation called");
	return (this->_n >= other._n);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '<=' overloaded operation called");
	return (this->_n <= other._n);
}

bool	Fixed::operator==(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '==' overloaded operation called");
	return (this->_n == other._n);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '!=' overloaded operation called");
	return (this->_n != other._n);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '+' overloaded operation called");
	Fixed result;

	result._n = this->_n + other._n;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '-' overloaded operation called");
	Fixed result;

	result._n = this->_n - other._n;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '*' overloaded operation called");
	Fixed result;

	result._n = (this->_n * other._n) >> this->_fPoint;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	LOG_DEBUG("[Fixed] '/' overloaded operation called");
	Fixed result;

	result._n = (this->_n / other._n) << this->_fPoint;
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	LOG_DEBUG("[Fixed] '++' overloaded pre-processor called");
	this->_n++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	LOG_DEBUG("[Fixed] '--' overloaded pre-processor called");
	this->_n--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	LOG_DEBUG("[Fixed] '++' overloaded post-processor called");
	Fixed copy = *this;

	this->_n++;
	return (copy);
}

Fixed	Fixed::operator--(int)
{
	LOG_DEBUG("[Fixed] '--' overloaded post-processor called");
	Fixed copy = *this;

	this->_n--;
	return (copy);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	LOG_DEBUG("[Fixed] 'min' member function called");
	if (a._n > b._n)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	LOG_DEBUG("[Fixed] 'min' const member function called");
	if (a._n > b._n)
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	LOG_DEBUG("[Fixed] 'max' member function called");
	if (a._n > b._n)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	LOG_DEBUG("[Fixed] 'max' const member function called");
	if (a._n > b._n)
		return (a);
	return (b);
}
