/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/31 14:18:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "structures.h"
#include "image.h"

typedef struct s_b_line
{
	t_pixel	dp;
	t_pixel	ds;

	int		err;
	int		e2;
}			t_b_line;

static	t_b_line	set_bresenham(t_pixel a, t_pixel b)
{
	t_b_line line;
	
	line.dp.x = abs(b.x - a.x);
	line.dp.y = abs(b.y - a.y);
	line.ds.x = (b.x > a.x) - (b.x < a.x);
	line.ds.y = (b.y > a.y) - (b.y < a.y);
	line.err = line.dp.x - line.dp.y;
	line.e2 = 2 * line.err;
	return (line);
}

static double	get_progress(t_pixel p, t_pixel a, t_pixel b)
{
	double	t;

	t = (p.x - a.x)*(p.x - a.x) + (p.y - a.y)*(p.y - a.y);
	t /= (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
	return (t);
}

void	bresenham_line(t_pixel a, t_pixel b, t_fdf *fdf)
{
	t_b_line	line;
	t_pixel		p;
	double		t;
	
	line = set_bresenham(a, b);
	p = a;
	while (b.x != p.x || b.y != p.y)
	{
		t = get_progress(p, a, b);
		p.color = blend_colors(a.color, b.color, t);
		set_pixel(p, fdf->data);
		if (line.e2 > -line.dp.y)
		{
			line.err -= line.dp.y;
			p.x += line.ds.x;
		}
		if (line.e2 < line.dp.x)
		{
			line.err += line.dp.x;
			p.y += line.ds.y;
		}
		line.e2 = 2 * line.err;
	}
	set_pixel(b, fdf->data);
}
