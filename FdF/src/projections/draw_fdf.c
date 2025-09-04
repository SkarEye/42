/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/04 21:43:43 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "image.h"
#include "math_helper.h"
#include "utils.h" // for map utils, too much ??

typedef struct s_b_line
{
	t_pixel	a;
	t_pixel	b;
	t_pixel	dp;
	t_pixel	ds;

	int		err;
	int		e2;

	float	d;
}			t_b_line;

static void	get_matrix(float m[3][3], t_pov cam)
{
	t_vect3d	c;
	t_vect3d	s;

	c = set_vect3d(cosf(cam.a.x), cosf(cam.a.y), cosf(cam.a.z));
	s = set_vect3d(sinf(cam.a.x), sinf(cam.a.y), sinf(cam.a.z));
	m[0][0] = c.y * c.z;
	m[0][1] = -c.y * s.z;
	m[0][2] = s.y;
	m[1][0] = s.x * s.y * c.z + c.x * s.z;
	m[1][1] = -s.x * s.y * s.z + c.x * c.z;
	m[1][2] = -s.x * c.y;
	m[2][0] = -c.x * s.y * c.z + s.x * s.z;
	m[2][1] = c.x * s.y * s.z + s.x * c.z;
	m[2][2] = c.x * c.y;
}

static t_pixel	project(t_vect3d p, t_fdf *fdf)
{
	t_pov		c;
	t_vect3d	v;
	t_vect3d	r;
	t_pixel		pxl;
	float		m[3][3];
	float		scale;

	c = fdf->cam;
	get_matrix(m, c);
	v = set_vect3d(p.x - c.p.x, p.y - c.p.y, p.z - c.p.z);
	r.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
	r.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
	r.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
	if (c.fov < 70)
		c.fov = 70;
	else if (c.fov > 180)
		c.fov = 180;
	if (r.z < 0.001f)
		r.z = 0.001f;
	scale = (0.5 * PXL_W) / tanf(rad(c.fov) / 2.0) / r.z;
	pxl.x = (int)(r.x * scale + (PXL_W / 2));
	pxl.y = (int)(r.y * scale + (PXL_H / 2));
	return (pxl);
}


static	t_b_line	set_bresenham(size_t a, size_t b, t_fdf *fdf)
{
	t_b_line l;

	l.a = project(fdf->map[a], fdf);
	l.b = project(fdf->map[b], fdf);
	l.dp.x = abs(l.b.x - l.a.x);
	l.dp.y = abs(l.b.y - l.a.y);
	l.ds.x = (l.b.x > l.a.x) - (l.b.x < l.a.x);
	l.ds.y = (l.b.y > l.a.y) - (l.b.y < l.a.y);
	l.err = l.dp.x - l.dp.y;
	l.e2 = 2 * l.err;
	l.d = (l.b.x - l.a.x) * (l.b.x - l.a.x) + (l.b.y - l.a.y) * (l.b.y - l.a.y);
	return (l);
}

static void	bresenham_line(size_t a, size_t b, t_fdf *fdf)
{
	t_b_line		l;
	t_pixel			p;
	float			t;
	unsigned int	color;

	l = set_bresenham(a, b, fdf);
	p = l.a;
	while (l.b.x != p.x || l.b.y != p.y)
	{
		t = ((p.x - l.a.x) * (p.x - l.a.x) + (p.y - l.a.y) * (p.y - l.a.y)) / l.d;
		color = blend_colors(fdf->colors[a], fdf->colors[b], t);
		set_pixel(p, color, fdf->data);
		if (l.e2 > -l.dp.y)
		{
			l.err -= l.dp.y;
			p.x += l.ds.x;
		}
		if (l.e2 < l.dp.x)
		{
			l.err += l.dp.x;
			p.y += l.ds.y;
		}
		l.e2 = 2 * l.err;
	}
	set_pixel(l.b, fdf->colors[b], fdf->data);
}

#include <stdio.h>

void	draw_fdf(t_fdf *fdf)
{
	size_t	x;
	size_t	z;

	z = 0;
	while (z < fdf->map_h) // j+1 ?????
	{
		x = 0;
		printf("in draw_fdf, drawing x: %zu, z: %zu...\n", x, z);
		while (x < fdf->map_w)
		{
			if (x + 1 < fdf->map_w)
				bresenham_line(pos(x, z, fdf), pos(x + 1, z, fdf), fdf);
			if (z + 1 < fdf->map_h)
				bresenham_line(pos(x, z, fdf), pos(x, z + 1, fdf), fdf);
			x++;
		}
		z++;
	}
}
