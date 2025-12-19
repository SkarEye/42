/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:50:03 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 20:24:04 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//what is better const int or int const ?

Point::Point(void) : _x(), _y() {}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}

Point::Point(Point const &other)  : _x(other._x), _y(other._y) {}

Point::~Point(void) {}

Fixed	Point::x(void) const
{
	return (this->_x);
}

Fixed	Point::y(void) const
{
	return (this->_y);
}

bool Point::operator==(const Point &other) const
{
	return ((this->_x == other._x) && (this->_y == other._y));
}

bool Point::operator!=(const Point &other) const
{
	return ((this->_x != other._x) || (this->_y != other._y));
}
