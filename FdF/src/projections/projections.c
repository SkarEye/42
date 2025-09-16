/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:53:50 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 19:14:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "math_helper.h"
#include "projections.h"

/**
 * @brief Draws a wireframe model from a given camera POV in a given color.
 *
 * @param cam Camera POV
 * @param c Color value
 * @param fdf FDF pointer
 * @note If c is set to 0, then the wireframe colors each node with its preset
 * color.
 */
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

/**
 * @brief Draws an anaglyph 3D wireframe model from a given camera POV.
 *
 * @param fdf FDF pointer
 * */
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
