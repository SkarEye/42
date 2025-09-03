/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:07:48 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/03 20:06:37 by macarnie         ###   ########.fr       */
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

void	set_cam(double pos[3], double ang[3], double fov, t_fdf *fdf)
{
	fdf->cam.x = pos[0];
	fdf->cam.y = pos[1];
	fdf->cam.z = pos[2];
	fdf->cam.u = ang[0];
	fdf->cam.v = ang[1];
	fdf->cam.w = ang[2];
	fdf->cam.fov = fov;
}

void	set_isometric_cam(t_fdf *fdf)
{
	double	pos[3] = {
		fdf->map_w / 2.0, (fdf->map_w + fdf->map_h) / 2, fdf->map_h / 2};
	double	ang[3] = {
		rad(35.264), 0, rad(45)};
		set_cam(pos, ang, 120, fdf);
}

void	set_45_cam(t_fdf *fdf)
{
	double	pos[3] = {
		fdf->map_w / 2.0, (fdf->map_w + fdf->map_h) / 2, fdf->map_h / 2};
	double	ang[3] = {
		rad(45), 0, rad(45)};
		set_cam(pos, ang, 120, fdf);
}

void	set_spawned_cam(t_fdf *fdf)
{
	double	pos[3] = {
		fdf->map_w / 2, 6, fdf->map_h / 2};
	double	ang[3] = {
		rad(-20), 0, 0};
		set_cam(pos, ang, 120, fdf);
}

void	set_vertical_cam(t_fdf *fdf)
{
	double	pos[3] = {
		fdf->map_w / 2, 15, fdf->map_h / 2};
	double	ang[3] = {
		rad(-90), 0, 0};
		set_cam(pos, ang, 150, fdf);
}

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
	get_matrix(m, c);
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
