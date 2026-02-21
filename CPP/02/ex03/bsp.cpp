/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:32:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/21 15:20:22 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define GRID_SIZE	40

#define ANSI_RED		"\033[31m"
#define ANSI_RESET		"\033[0m"

// bool	bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	s, t, d;

// 	s = (a.x() - c.x()) * (point.y() - c.y()) - (a.y() - c.y()) * (point.x() - c.x());
// 	t = (b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
// 	if (((s < 0) != (t < 0)) && (s != 0) && (t != 0))
// 		return (false);
// 	d = (c.x() - b.x()) * (point.y() - b.y()) - (c.y() - b.y()) * (point.x() - b.x());
// 	return ((d == 0) || ((d < 0) == (s + t <= 0)));
// }

static Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	return (p1.x() - p3.x()) * (p2.y() - p3.y())
	     - (p2.x() - p3.x()) * (p1.y() - p3.y());
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed d1 = sign(p, a, b);
	Fixed d2 = sign(p, b, c);
	Fixed d3 = sign(p, c, a);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return (!(has_neg && has_pos));
}


// void	printTriangle(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	max_x = Fixed::max(a.x(), Fixed::max(b.x(), c.x())),
// 			min_x = Fixed::min(a.x(), Fixed::min(b.x(), c.x())),
// 			max_y = Fixed::max(a.y(), Fixed::max(b.y(), c.y())),
// 			min_y = Fixed::min(a.y(), Fixed::min(b.y(), c.y())),
// 			step_x = (max_x - min_x) / Fixed(GRID_SIZE),
// 			step_y = (max_y - min_y) / Fixed(GRID_SIZE);

// 	for (int y = GRID_SIZE; y > 0; y--)
// 	{
// 		for (int x = 0; x < GRID_SIZE * 2; x++)
// 		{
// 			Point pixel(
// 			min_x + Fixed(x) * step_x / 2,
// 			min_y + Fixed(y) * step_y);

// 			if ((pixel.x() - point.x()).abs() < step_x.abs()
// 			&& (pixel.y() - point.y()).abs() < step_y.abs())
// 				std::cout << ANSI_RED << 'o' << ANSI_RESET;
// 			else if (bsp(a, b, c, pixel))
// 				std::cout << 'o';
// 			else
// 			 	std::cout << '.';
// 		}
// 		std::cout << '\n';
// 	}
// }
