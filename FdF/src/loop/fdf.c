/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:45:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:32:59 by macarnie         ###   ########.fr       */
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

static void	handle_pos(int key, t_fdf *fdf)
{
	if (key == XK_w)
	{
		fdf->cam.p.x += cos(fdf->cam.a.y - PI / 2) * MOVE_SPEED;
		fdf->cam.p.z += sin(fdf->cam.a.y - PI / 2) * MOVE_SPEED;
	}
	if (key == XK_a)
	{
		fdf->cam.p.x -= cos(fdf->cam.a.y) * MOVE_SPEED;
		fdf->cam.p.z -= sin(fdf->cam.a.y) * MOVE_SPEED;
	}
	if (key == XK_s)
	{
		fdf->cam.p.x += cos(fdf->cam.a.y + PI / 2) * MOVE_SPEED;
		fdf->cam.p.z += sin(fdf->cam.a.y + PI / 2) * MOVE_SPEED;
	}
	if (key == XK_d)
	{
		fdf->cam.p.x += cos(fdf->cam.a.y) * MOVE_SPEED;
		fdf->cam.p.z += sin(fdf->cam.a.y) * MOVE_SPEED;
	}
	if (key == XK_space)
		fdf->cam.p.y += MOVE_SPEED;
	if (key == XK_Shift_L)
		fdf->cam.p.y -= MOVE_SPEED;
}

int	handle_fdf(int key, t_fdf *fdf)
{
	handle_pos(key, fdf);
	if (key == XK_Up)
		fdf->cam.a.x += ROT_SPEED;
	if (key == XK_Down)
		fdf->cam.a.x -= ROT_SPEED;
	if (key == XK_Left)
		fdf->cam.a.y -= ROT_SPEED;
	if (key == XK_Right)
		fdf->cam.a.y += ROT_SPEED;
	if (key == XK_q)
		fdf->cam.a.z -= ROT_SPEED;
	if (key == XK_e)
		fdf->cam.a.z += ROT_SPEED;
	if (key == XK_plus || key == XK_equal)
		fdf->cam.fov -= ZOOM_SPEED;
	if (key == XK_minus)
		fdf->cam.fov += ZOOM_SPEED;
	return (0);
}

#include <stdio.h>

#include "utils.h"

static void	print_map(t_fdf *fdf)
{
	size_t	x, z;

	printf("Printing Map...\n\n");
	z = 0;
	while (z < fdf->map_h)
	{
		x = 0;
		while (x < fdf->map_w)
		{
			printf("%f ", fdf->map[pos(x, z, fdf)].y);
			x++;
		}
		printf("\n");
		z++;
	}

}

int	render_fdf(t_fdf *fdf)
{
	printf("in render_fdf\n");
	print_map(fdf);
	draw_fdf(fdf);
	return (0);
}