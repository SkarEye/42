/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:07:48 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/31 17:05:48 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "structures.h"
#include "math_helper.h"

static void	get_matrix(double m[3][3], t_pov c)
{
	double	c_u;
	double	s_u;
	double	c_v;
	double	s_v;
	double	c_w;
	double	s_w;

	c_u = cos(c.u);
	s_u = sin(c.u);
	c_v = cos(c.v);
	s_v = sin(c.v);
	c_w = cos(c.w);
	s_w = sin(c.w);
	m[0][0] = c_v * c_w;
	m[0][1] = -c_v * s_w;
	m[0][2] = s_v;
	m[1][0] = s_u * s_v * c_w + c_u * s_w;
	m[1][1] = -s_u * s_v * s_w + c_u * c_w;
	m[1][2] = -s_u * c_v;
	m[2][0] = -c_u * s_v * c_w + s_u * s_w;
	m[2][1] = c_u * s_v * s_w + s_u * c_w;
	m[2][2] = c_u * c_v;
}

void	set_

t_pixel	project(t_point p, t_fdf *fdf)
{
	t_pixel	pxl;
	t_pov	c;
	double	px;
	double	py;
	double	pz;
	double	m[3][3];
	double	scale;

	c = fdf->cam;
	px = m[0][0] * (p.x - c.x) + m[0][1] * (p.y - c.y) + m[0][2] * (p.z - c.z);
	py = m[1][0] * (p.x - c.x) + m[1][1] * (p.y - c.y) + m[1][2] * (p.z - c.z);
	pz = m[2][0] * (p.x - c.x) + m[2][1] * (p.y - c.y) + m[2][2] * (p.z - c.z);
	if (c.fov < 70)
		c.fov = 70;
	else if (c.fov > 180)
		c.fov = 180;
	scale = (0.5 * PXL_W) / tan(rad(c.fov) / 2.0) / (pz + 1.0);
	pxl.x = px * scale + (PXL_W / 2);
	pxl.y = py * scale + (PXL_H / 2);
	pxl.color = p.color;
	return (pxl);
}
