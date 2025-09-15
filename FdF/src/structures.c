/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:51:11 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:43 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "structures.h"

t_vect3d	set_vect3d(float x, float y, float z)
{
	t_vect3d	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

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

t_txt	set_txt(t_pos2d size, unsigned int color, int scale, t_align align)
{
	t_txt txt;

	txt.size = size;
	txt.color = color;
	if (scale < 1)
		txt.scale = 1;
	else
		txt.scale = scale; //should this be done here ??
	if (align < A_LEFT ||align > A_UNKNOWN)
		txt.align = A_UNKNOWN;
	else
		txt.align = align;
	return (txt);
}