/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:53:50 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:54:09 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "math_helper.h"
#include "projections.h"

void	draw_fdf(t_pov cam, unsigned int c, t_fdf *fdf)
{
	size_t	i;
	size_t	x;
	size_t	z;

	i = 0;
	while (i < fdf->map_w * fdf->map_h)
		project(&fdf->map[i++], cam);
	z = 0;
	while (z < fdf->map_h)
	{
		x = 0;
		while (x < fdf->map_w)
		{
			i = z * fdf->map_w + x;
			if (x + 1 < fdf->map_w)
				bresenham(fdf->map[i].l, fdf->map[i + 1].l, c, fdf);
			if (z + 1 < fdf->map_h)
				bresenham(fdf->map[i].l, fdf->map[i + fdf->map_w].l, c, fdf);
			x++;
		}
		z++;
	}
}

void	draw_3d(t_fdf *fdf)
{
	t_pov		left_eye;
	t_pov		right_eye;
	float		sep;

	sep = sqrtf(fdf->map_w * fdf->map_w + fdf->map_h * fdf->map_h) * 0.02f;
	left_eye = fdf->cam;
	right_eye = fdf->cam;
	left_eye.v.x -= fdf->cam.m[0][0] * sep;
	left_eye.v.y -= fdf->cam.m[1][0] * sep;
	left_eye.v.z -= fdf->cam.m[2][0] * sep;
	right_eye.v.x += fdf->cam.m[0][0] * sep;
	right_eye.v.y += fdf->cam.m[1][0] * sep;
	right_eye.v.z += fdf->cam.m[2][0] * sep;
	draw_fdf(left_eye, 0xFF0000, fdf);
	draw_fdf(right_eye, 0x00FFFF, fdf);
}
/*
void	draw_3d(t_fdf *fdf)
{
	t_pov		left_eye;
	t_pov		right_eye;
	t_vect3d	right;
	t_vect3d	c;
	t_vect3d	s;
	float		sep;

	sep = sqrtf(fdf->map_w * fdf->map_w + fdf->map_h * fdf->map_h) * 0.02f;
	c = set_vect3d(cosf(fdf->cam.r.x), cosf(fdf->cam.r.y), cosf(fdf->cam.r.z));
	s = set_vect3d(sinf(fdf->cam.r.x), sinf(fdf->cam.r.y), sinf(fdf->cam.r.z));
	left_eye = fdf->cam;
	right_eye = fdf->cam;
	right.x = c.y * c.z;
	right.y = s.x * s.y * c.z + c.x * s.z;
	right.z = -c.x * s.y * c.z + s.x * s.z;
	left_eye.v.x -= right.x * sep;
	left_eye.v.y -= right.y * sep;
	left_eye.v.z -= right.z * sep;
	right_eye.v.x += right.x * sep;
	right_eye.v.y += right.y * sep;
	right_eye.v.z += right.z * sep;
	draw_fdf(left_eye, 0xFF0000, fdf);
	draw_fdf(right_eye, 0x00FFFF, fdf);
}
*/