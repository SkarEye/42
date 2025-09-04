/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 13:43:10 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	set_pixel(t_pixel p, unsigned int color, t_data *data)
{
	char	*dst;

	if (p.x >= data->pxl_w || p.x < 0 || p.y >= data->pxl_h || p.y < 0)
		return ;
	dst = data->addr + (p.y * data->line_length + p.x * (data->bits_pxl / 8));
	*(unsigned int *)dst = p.color;
}

unsigned int	get_pixel(t_pixel p, t_data *data)
{
	char	*color;

	if (!data ||p.x >= data->pxl_w|| p.x < 0 || p.y >= data->pxl_h || p.y < 0)
		return (0);
	color = data->addr + p.y * data->line_length + p.x * (data->bits_pxl / 8);
	return (*(unsigned int *)color);
}
void	scale_pixel(t_pixel p, unsigned int color, int scale, t_data *dst)
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
			set_pixel((t_pixel){p.x + i++, p.y + j}, color, dst);
		j++;
	}
}

unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, double t)
{
	int	r;
	int	g;
	int	b;

	if (t < 0)
		return (src_c);
	if (t > 1)
		return (dst_c);
	r = ((1 - t) * ((src_c >> 16) & 0xFF)) + (t * ((dst_c >> 16) & 0xFF));
	g = ((1 - t) * ((src_c >> 8) & 0xFF)) + (t * ((dst_c >> 8) & 0xFF));
	b = ((1 - t) * (src_c & 0xFF)) + (t * (dst_c & 0xFF));
	return (r << 16 | g << 8 | b);
}