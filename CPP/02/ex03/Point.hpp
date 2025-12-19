/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:19:47 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 20:33:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const &other);
		Point& operator=(const Point& other);
		~Point();

		Fixed	x(void) const;
		Fixed	y(void) const;
		
		bool	operator!=(Point const &other) const;
		bool	operator==(Point const &other) const;
};

#endif