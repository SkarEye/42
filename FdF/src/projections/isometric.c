/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:03:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/30 14:15:31 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "structures.h"

void	isometric(t_fdf *fdf)
{
	size_t	i;
	t_point	*p;
	double	a;

	i = 0;
	a = 30 * M_PI / 180;
	while (i < fdf->map_h * fdf->map_w)
	{
		*p = fdf->map[i];
		p->p_x = (p->x - p->y) * cos(a);
		p->p_y = (p->x + p->y) * sin(a) - p->z;
		i++;
	}
}
