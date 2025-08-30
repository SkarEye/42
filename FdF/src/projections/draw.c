/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/30 18:44:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "structures.h"

void set_pixel(t_pixel p, t_data *data)
{
	char *dst;

	if (p.x > data->pxl_w || p.x < 0 || p.y > data->pxl_h || p.y < 0)
		return ;
	dst = data->addr + (p.y * data->line_length + p.x * (data->bits_pxl / 8));
	*(unsigned int *)dst = p.color;
}

t_pixel project(t_point p, t_point pov, double zoom, t_fdf *fdf)
{
	t_pixel	pxl;

	pxl.x = (p.x - pov.x) * zoom + (fdf->data->pxl_w / 2);
	pxl.y = (p.y - pov.y) * zoom + (fdf->data->pxl_h / 2);
	pxl.color = p.color;
	return (pxl);
}

static t_b_line	set_bresenham(t_pixel a, t_pixel b)
{
	t
}

void bresenham_line(t_pixel a, t_pixel b, t_fdf *fdf)
{
	t_pixel dp;
	t_pixel ds;
	int err;

	dp.x = abs(b.x - a.x);
	dp.y = abs(b.y - a.y);
	ds.x = (b.x > a.x) - (b.x < a.x);
	ds.y = (b.y > a.y) - (b.y < a.y);
	err = dp.x - dp.y;

	while (1)
	{
		set_pixel(a, fdf->data);
		if (b.x == a.x && b.y == a.y)
			break;
		if (e2 > -dp.y)
		{
			err -= dp.y;
			a.x += ds.x;
		}
		if (e2 < dp.x)
		{
			err += dp.x;
			a.y += ds.y;
		}
		a.color = blend_colors(a, b,)
	}
}
