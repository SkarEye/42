/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/04 15:14:39 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "image.h"
#include "math_helper.h"

typedef struct s_b_line
{
	t_pixel	a;
	t_pixel	b;
	t_pixel	dp;
	t_pixel	ds;
	
	int		err;
	int		e2;

	double	d;
}			t_b_line;

static void	get_matrix(double m[3][3], t_pov c)
{
	double	c_x;
	double	s_x;
	double	c_y;
	double	s_y;
	double	c_z;
	double	s_z;

	c_x = cos(c.a.x);
	s_x = sin(c.a.x);
	c_y = cos(c.a.y);
	s_y = sin(c.a.y);
	c_z = cos(c.a.z);
	s_z = sin(c.a.z);
	m[0][0] = c_y * c_z;
	m[0][1] = -c_y * s_z;
	m[0][2] = s_y;
	m[1][0] = s_x * s_y * c_z + c_x * s_z;
	m[1][1] = -s_x * s_y * s_z + c_x * c_z;
	m[1][2] = -s_x * c_y;
	m[2][0] = -c_x * s_y * c_z + s_x * s_z;
	m[2][1] = c_x * s_y * s_z + s_x * c_z;
	m[2][2] = c_x * c_y;
}

static t_pixel	project(t_point p, t_fdf *fdf)
{
	t_pov		c;
	t_vect3d	d;
	t_pixel		pxl;
	double		m[3][3];
	double		scale;

	c = fdf->cam;
	get_matrix(m, c);
	d = set_vect3d(p.p.x - c.p.x, p.p.y - c.p.y, p.p.z - c.p.z);
	p.p.x = m[0][0] * d.x + m[0][1] * d.y + m[0][2] * d.z;
	p.p.y = m[1][0] * d.x + m[1][1] * d.y + m[1][2] * d.z;
	p.p.z = m[2][0] * d.x + m[2][1] * d.y + m[2][2] * d.z;
	if (c.fov < 70)
		c.fov = 70;
	else if (c.fov > 180)
		c.fov = 180;
	scale = (0.5 * PXL_W) / tan(rad(c.fov) / 2.0) / (d.z + 1.0);
	pxl.x = d.x * scale + (PXL_W / 2);
	pxl.y = d.y * scale + (PXL_H / 2);
	return (pxl);
}


static	t_b_line	set_bresenham(t_point a, t_point b, t_fdf *fdf)
{
	t_b_line l;
	
	l.a = project(a, fdf);
	l.b = project(b, fdf);
	l.dp.x = abs(l.b.x - l.a.x);
	l.dp.y = abs(l.b.y - l.a.y);
	l.ds.x = (l.b.x > l.a.x) - (l.b.x < l.a.x);
	l.ds.y = (l.b.y > l.a.y) - (l.b.y < l.a.y);
	l.err = l.dp.x - l.dp.y;
	l.e2 = 2 * l.err;
	l.d = (l.b.x - l.a.x) * (l.b.x - l.a.x) + (l.b.y - l.a.y) * (l.b.y - l.a.y);
	return (l);
}

//how tf should i do pixels ???
static void	bresenham_line(t_point a, t_point b, t_fdf *fdf)
{
	t_b_line		l;
	t_pixel			p;
	double			t;
	unsigned int	color;
	
	l = set_bresenham(a, b, fdf);
	p = l.a;
	while (l.b.x != p.x || l.b.y != p.y)
	{
		t = (p.x - l.a.x)*(p.x - l.a.x) + (p.y - l.a.y)*(p.y - l.a.y) / l.d;
		color = blend_colors(a.color, b.color, t);
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
	set_pixel(l.b, b.color, fdf->data);
}


//needs to be 25 or less
void	draw_fdf(t_fdf *fdf)
{
	size_t	x;
	size_t	z;

	z = 0;
	while (z < fdf->map_h) // j+1 ?????
	{
		x = 0;
		while (x < fdf->map_w)
		{
			if (x + 1 < fdf->map_w)
				bresenham_line(fdf->map[z * fdf->map_w + x], fdf->map[z * fdf->map_w + x + 1], fdf); //pos func could be good ??
			if (z + 1 < fdf->map_h)
				bresenham_line(fdf->map[z * fdf->map_w + x], fdf->map[(z + 1) * fdf->map_w + x], fdf);
			x++;
		}
		z++;
	}
	return (0);
}
