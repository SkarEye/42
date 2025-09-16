/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 14:54:20 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "projections.h"
#include "image.h"
#include "math_helper.h"

static	t_b_line	set_bresenham(t_pos2d a, t_pos2d b)
{
	t_b_line	l;

	l.p = a;
	l.dp.x = abs(b.x - a.x);
	l.dp.y = abs(b.y - a.y);
	l.ds.x = (b.x > a.x) - (b.x < a.x);
	l.ds.y = (b.y > a.y) - (b.y < a.y);
	l.err = l.dp.x - l.dp.y;
	l.e2 = 2 * l.err;
	l.d = l.dp.x + l.dp.y;
	return (l);
}

static void	update_bresenham(t_b_line *l)
{
	if (l->e2 > -l->dp.y)
	{
		l->err -= l->dp.y;
		l->p.x += l->ds.x;
	}
	if (l->e2 < l->dp.x)
	{
		l->err += l->dp.x;
		l->p.y += l->ds.y;
	}
	l->e2 = 2 * l->err;
}

void	bresenham(t_pixel a, t_pixel b, unsigned int c, t_fdf *fdf)
{
	t_b_line	l;
	float		t;

	if (!a.is_valid || !b.is_valid)
		return ;
	l = set_bresenham(a.p, b.p);
	while (b.p.x != l.p.x || b.p.y != l.p.y)
	{
		if (c)
			add_pixel(l.p, c, fdf->data);
		else
		{
			t = (abs(l.p.x - a.p.x) + abs(l.p.y - a.p.y)) / l.d;
			add_pixel(l.p, blend_colors(a.c, b.c, t), fdf->data);
		}
		update_bresenham(&l);
	}
	if (c)
		add_pixel(b.p, c, fdf->data);
	else
		add_pixel(b.p, b.c, fdf->data);
}
