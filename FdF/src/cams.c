/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cams.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:23:46 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:34:43 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "math_helper.h"

void	set_vertical(t_fdf *fdf)
{
	fdf->cam.v = set_vect3d(fdf->map_w / 2.0, 15, fdf->map_h / 2.0);
	fdf->cam.r = set_vect3d(rad(-90), 0, 0);
	fdf->cam.fov = 120.0;
}

void	set_horizontal(t_fdf *fdf)
{
	fdf->cam.v = set_vect3d(fdf->map_w / 2.0, 5, -10);
	fdf->cam.r = set_vect3d(rad(180), rad(180), 0);
	fdf->cam.fov = 120.0;
}

void	set_isometric(t_fdf *fdf)
{
	float	dist;

	dist = sqrtf(fdf->map_w * fdf->map_w + fdf->map_h * fdf->map_h) * 1.5f;
	fdf->cam.v = set_vect3d(0.707 * dist, 0.577 * dist, 0.707 * dist);
	fdf->cam.r = set_vect3d(rad(215.264), rad(-45), 0);
	fdf->cam.fov = 60.0;
}
