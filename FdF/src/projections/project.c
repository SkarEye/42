/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:07:48 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 11:40:53 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "structures.h"
#include "math_helper.h"

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

t_vect3d	set_vect3d(double x, double y, double z)
{
	t_vect3d	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_pov	set_pov(t_vect3d pos, t_vect3d ang, double fov)
{
	t_pov	pov;
	
	pov.p = pos;
	pov.a = ang;
	pov.fov = fov;
	return (pov);
}

void	set_vertical_cam(t_fdf *fdf)
{
	t_vect3d	pos;
	t_vect3d	ang;

	pos = set_vect3d(fdf->map_w / 2, 15, fdf->map_h / 2);
	ang = set_vect3d(rad(-90), 0, 0);
	set_pov(pos, ang, 120);	
}

t_pixel	project(t_vect3d p, unsigned int color, t_fdf *fdf)
{
	t_pov		c;
	t_vect3d	d;
	t_pixel		pxl;
	double		m[3][3];
	double		scale;

	c = fdf->cam;
	get_matrix(m, c);
	d = set_vect3d(p.x - c.p.x, p.y - c.p.y, p.z - c.p.z);
	p.x = m[0][0] * d.x + m[0][1] * d.y + m[0][2] * d.z;
	p.y = m[1][0] * d.x + m[1][1] * d.y + m[1][2] * d.z;
	p.z = m[2][0] * d.x + m[2][1] * d.y + m[2][2] * d.z;
	if (c.fov < 70)
		c.fov = 70;
	else if (c.fov > 180)
		c.fov = 180;
	scale = (0.5 * PXL_W) / tan(rad(c.fov) / 2.0) / (d.z + 1.0);
	pxl.x = d.x * scale + (PXL_W / 2);
	pxl.y = d.y * scale + (PXL_H / 2);
	pxl.color = color;
	return (pxl);
}
