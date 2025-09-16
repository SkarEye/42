/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:24:52 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:55:32 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "math_helper.h"

static void	perspective(t_vect3d r, t_point *point, t_pov cam)
{
	float	scale;

	scale = cam.focal / r.z;
	point->l.p.x = (int)(r.x * scale + (PXL_W / 2));
	point->l.p.y = (int)(r.y * scale + (PXL_H / 2));
	point->l.is_valid = true;
}

static void	fisheye(t_vect3d r, t_point *point, t_pov cam)
{
	float		theta;
	float		phi;
	float		radius;

	theta = acosf(r.z);
	phi = atan2f(r.y, r.x);
	radius = (theta / (cam.fov * (PI / 180.0f))) * (PXL_W / 2);
	point->l.p.x = (int)(PXL_W / 2 + radius * cosf(phi));
	point->l.p.y = (int)(PXL_H / 2 + radius * sinf(phi));
	point->l.is_valid = true;
}

/**
 * @brief Projects a 3D position into to 2D related to the given POV
 *
 * @param point Point that stores its 3D coordinates and projected 2D ones
 * @param cam Camera POV
 */
void	project(t_point *point, t_pov cam)
{
	t_vect3d	v;
	t_vect3d	r;
	float		len;

	v.x = point->v.x - cam.v.x;
	v.y = point->v.y - cam.v.y;
	v.z = point->v.z - cam.v.z;
	r.x = cam.m[0][0] * v.x + cam.m[0][1] * v.y + cam.m[0][2] * v.z;
	r.y = cam.m[1][0] * v.x + cam.m[1][1] * v.y + cam.m[1][2] * v.z;
	r.z = cam.m[2][0] * v.x + cam.m[2][1] * v.y + cam.m[2][2] * v.z;
	len = sqrtf(r.x * r.x + r.y * r.y + r.z * r.z);
	r = set_vect3d(r.x / len, r.y / len, r.z / len);
	if (!cam.is_fish && r.z > 0.05f)
		perspective(r, point, cam);
	else if (cam.is_fish && len > 0.001f)
		fisheye(r, point, cam);
	else
		point->l.is_valid = false;
}

/**
 * @brief Calculates the rotation matrix of the camera's pitch/yaw/roll.
 *
 * @param cam Camera POV
 */
void	get_matrix(t_pov *cam)
{
	t_vect3d	c;
	t_vect3d	s;

	c = set_vect3d(cosf(cam->r.x), cosf(cam->r.y), cosf(cam->r.z));
	s = set_vect3d(sinf(cam->r.x), sinf(cam->r.y), sinf(cam->r.z));
	cam->m[0][0] = c.y * c.z;
	cam->m[0][1] = -c.y * s.z;
	cam->m[0][2] = s.y;
	cam->m[1][0] = s.x * s.y * c.z + c.x * s.z;
	cam->m[1][1] = -s.x * s.y * s.z + c.x * c.z;
	cam->m[1][2] = -s.x * c.y;
	cam->m[2][0] = -c.x * s.y * c.z + s.x * s.z;
	cam->m[2][1] = c.x * s.y * s.z + s.x * c.z;
	cam->m[2][2] = c.x * c.y;
}
