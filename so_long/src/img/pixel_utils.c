/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:15:32 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 13:09:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

#include "img_utils.h"

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char	*p;

	if (!data)
		return (0);
	if (x > data->p_w|| x < 0 || y > data->p_h || y < 0)
		return (0);
	p = data->addr + y * data->line_length + x * (data->bits_pxl / 8);
	return (*(unsigned int *)p);
}

void set_pixel_color(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x > data->p_w || x < 0 || y > data->p_h || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_pxl / 8));
	*(unsigned int *)dst = color;
}

void	scale_pixel(t_data *dst, int x, int y, int color, int scale)
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
			set_pixel_color(dst, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
