/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:36:28 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

/**
 * @brief Sets a given color value to a pixel.
 *
 * @param p Pixel position
 * @param c Color
 * @param data Image pointer
 */
void	set_pixel(t_pos2d p, unsigned int color, t_data *data)
{
	char	*dst;

	if (!data || p.x >= data->pxl_w || p.x < 0 || p.y >= data->pxl_h || p.y < 0)
		return ;
	if (color > 0xFFFFFF)
		color = 0xFFFFFF;
	dst = data->addr + (p.y * data->line_length + p.x * (data->bits_pxl / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Adds a given color value to a pixel.
 *
 * @param p Pixel position
 * @param c Color
 * @param data Image pointer
 */
void	add_pixel(t_pos2d p, unsigned int color, t_data *data)
{
	char	*dst;

	if (!data || p.x >= data->pxl_w || p.x < 0 || p.y >= data->pxl_h || p.y < 0)
		return ;
	dst = data->addr + (p.y * data->line_length + p.x * (data->bits_pxl / 8));
	color += *(unsigned int *)dst;
	if (color > 0xFFFFFF)
		color = 0xFFFFFF;
	*(unsigned int *)dst = color;
}

/**
 * @brief Gives the given color value of a pixel.
 *
 * @param p Pixel position
 * @param data Image pointer
 * @return Color value of the pixel.
 */
unsigned int	get_pixel(t_pos2d p, t_data *data)
{
	char	*src;

	if (!data || p.x >= data->pxl_w || p.x < 0 || p.y >= data->pxl_h || p.y < 0)
		return (0);
	src = data->addr + p.y * data->line_length + p.x * (data->bits_pxl / 8);
	return (*(unsigned int *)src);
}

void	scale_pixel(t_pos2d pos, unsigned int color, int scale, t_data *dst)
{
	t_pos2d	t;

	if (!dst)
		return ;
	t = pos;
	while (t.y < pos.y + scale)
	{
		t.x = pos.x;
		while (t.x < pos.x + scale)
		{
			set_pixel(t, color, dst);
			t.x++;
		}
		t.y++;
	}
}

unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, float t)
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
