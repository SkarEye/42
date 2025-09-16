/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gyroscope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:11:00 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:51:36 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "projections.h"

/**
 * @brief Draws a gyroscope representing the current view of the user's POV.
 *
 * @param pos Gyroscope position in window
 * @param fdf FDF pointer
 */
void	draw_gyroscope(t_pos2d pos, int scale, t_fdf *fdf)
{
	t_pixel		o;
	t_pixel		s;

	o.is_valid = true;
	s.is_valid = true;
	o.p.x = pos.x + scale;
	o.p.y = pos.y + scale;
	s.p.x = o.p.x + (int)(fdf->cam.m[0][0] * scale);
	s.p.y = o.p.y + (int)(fdf->cam.m[1][0] * scale);
	bresenham(o, s, 0xFF0000, fdf);
	s.p.x = o.p.x + (int)(fdf->cam.m[0][1] * scale);
	s.p.y = o.p.y + (int)(fdf->cam.m[1][1] * scale);
	bresenham(o, s, 0x00FF00, fdf);
	s.p.x = o.p.x + (int)(fdf->cam.m[0][2] * scale);
	s.p.y = o.p.y + (int)(fdf->cam.m[1][2] * scale);
	bresenham(o, s, 0x0000FF, fdf);
}
