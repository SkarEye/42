/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:32:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 21:02:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define GRID_SIZE	80

#define ANSI_BLACK		"\033[30m"
#define ANSI_RED		"\033[31m"
#define ANSI_RESET		"\033[0m"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	s, t, d;

	s = (a.x() - c.x()) * (point.y() - c.y()) - (a.y() - c.y()) * (point.x() - c.x());
	t = (b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
	if (((s < 0) != (t < 0)) && (s != 0) && (t != 0))
		return (false);
	d = (c.x() - b.x()) * (point.y() - b.y()) - (c.y() - b.y()) * (point.x() - b.x());
	return ((d == 0) || ((d < 0) == (s + t <= 0)));
}

void	printTriangle(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	max_x = Fixed::max(a.x(), Fixed::max(b.x(), c.x())),
			min_x = Fixed::min(a.x(), Fixed::min(b.x(), c.x())),
			max_y = Fixed::max(a.y(), Fixed::max(b.y(), c.y())),
			min_y = Fixed::min(a.y(), Fixed::min(b.y(), c.y())),
			epsilon(0.05f);

	for (int y = GRID_SIZE; y >= 0; --y)
	{
		for (int x = 0; x <= GRID_SIZE; ++x)
		{
			Point pixel(
			min_x + Fixed(x) * (max_x - min_x) / Fixed(GRID_SIZE),
			min_y + Fixed(y) * (max_y - min_y) / Fixed(GRID_SIZE));

			if ((pixel.x() - point.x()).abs() < epsilon
			&& (pixel.y() - point.y()).abs() < epsilon)
				std::cout << ANSI_RED << 'o' << ANSI_RESET;
			else if (bsp(a, b, c, pixel))
				std::cout << 'o';
			else
			 	std::cout << ANSI_BLACK << '.' << ANSI_RESET;
		}
		std::cout << '\n';
	}
}
