/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:45:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/03 19:56:36 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <X11/keysym.h>

#include "structures.h"
#include "projections.h"
#include "math_helper.h"

#define MOVE_SPEED 0.5
#define ROT_SPEED  0.05
#define ZOOM_SPEED 5.0

int	render(t_fdf *fdf)
{
	size_t	i;
	size_t	j;
	t_pixel	a;
	t_pixel	b;

	j = 0;
	while (j < fdf->map_h) // j+1 ?????
	{
		i = 0;
		while (i < fdf->map_w)
		{
			if (i + 1 < fdf->map_w)
			{
				a = project(fdf->map[j * fdf->map_w + i], fdf);
				b = project(fdf->map[j * fdf->map_w + i + 1], fdf);
				bresenham_line(a, b, fdf);
			}
			if (j + 1 < fdf->map_h)
			{
				a = project(fdf->map[j * fdf->map_w + i], fdf);
				b = project(fdf->map[(j + 1) * fdf->map_w + i], fdf);
				bresenham_line(a, b, fdf);
			}
			i++;
		}
		j++;
	}
	return (0);
}

static void	handle_pos(int key, t_fdf *fdf)
{
	if (key == XK_w)
	{
		fdf->cam.x += cos(fdf->cam.v - PI / 2) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.v - PI / 2) * MOVE_SPEED;
	}
	if (key == XK_a)
	{
		fdf->cam.x -= cos(fdf->cam.v) * MOVE_SPEED;
		fdf->cam.z -= sin(fdf->cam.v) * MOVE_SPEED;
	}
	if (key == XK_s)
	{
		fdf->cam.x += cos(fdf->cam.v + PI / 2) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.v + PI / 2) * MOVE_SPEED;
	}
	if (key == XK_d)
	{
		fdf->cam.x += cos(fdf->cam.v) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.v) * MOVE_SPEED;
	}
	if (key == XK_space)
		fdf->cam.y += MOVE_SPEED;
	if (key == XK_Shift_L)
		fdf->cam.y -= MOVE_SPEED;
}

int	handle_key(int key, t_fdf *fdf)
{
	handle_pos(key, fdf);
	if (key == XK_Up)
		fdf->cam.u += ROT_SPEED;
	if (key == XK_Down)
		fdf->cam.u -= ROT_SPEED;
	if (key == XK_Left)
		fdf->cam.v -= ROT_SPEED;
	if (key == XK_Right)
		fdf->cam.v += ROT_SPEED;
	if (key == XK_q)
		fdf->cam.w -= ROT_SPEED;
	if (key == XK_e)
		fdf->cam.w += ROT_SPEED;
	if (key == XK_plus || key == XK_equal)
		fdf->cam.fov -= ZOOM_SPEED;
	if (key == XK_minus)
		fdf->cam.fov += ZOOM_SPEED;
	return (0);
}