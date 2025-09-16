/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:51:11 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:10:51 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "structures.h"

/**
 * @brief Sets the parameters of a (t_vect3d) type.
 *
 * @param x
 * @param y
 * @param z
 * @returns A (t_vect3d) type.
 */
t_vect3d	set_vect3d(float x, float y, float z)
{
	t_vect3d	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

/**
 * @brief Sets the parameters of a (t_pov) type.
 *
 * @param v
 * @param r
 * @param fov
 * @returns A (t_pov) type.
 */
t_pov	set_pov(t_vect3d v, t_vect3d r, float fov)
{
	t_pov	pov;

	pov.v = v;
	pov.r = r;
	pov.fov = fov;
	pov.focal = 0;
	pov.is_fish = false;
	pov.is_3d = false;
	return (pov);
}

/**
 * @brief Sets the parameters of a (t_txt) type.
 *
 * @param size
 * @param color
 * @param scale
 * @param align
 * @returns A (t_txt) type.
 */
t_txt	set_txt(t_pos2d size, unsigned int color, int scale, t_align align)
{
	t_txt	txt;

	txt.size = size;
	txt.color = color;
	if (scale < 1)
		txt.scale = 1;
	else
		txt.scale = scale;
	if (align < A_LEFT || align > A_UNKNOWN)
		txt.align = A_UNKNOWN;
	else
		txt.align = align;
	return (txt);
}
