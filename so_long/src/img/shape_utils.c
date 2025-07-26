/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:27:49 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:57:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "structures.h"

#include "img_utils.h"

void	draw_square(t_data *dst, int x, int y, int color, int scale)
{
	int	i;
	int	j;

	if (!dst)
		return ;
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			set_pixel_color(dst, x, y, color);
			i++;
		}
		j++;
	}
}
