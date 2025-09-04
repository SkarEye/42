/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:51:11 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 14:59:42 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

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

t_txt	set_txt(t_pixel size, unsigned int color, int scale, t_align align)
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