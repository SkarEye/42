/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:09:25 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:56:27 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

//this func might be wrong
void	paste_image(t_pos2d p, int scale, t_data *src, t_data *dst)
{
	t_pos2d			s;
	t_pos2d			d;
	unsigned int	color;

	if (!dst || !src || scale < 1)
		return ;
	s.y = 0;
	d.y = p.y;
	while (s.y < src->pxl_h)
	{
		s.x = 0;
		d.x = p.x;
		while (s.x < src->pxl_w)
		{
			color = get_pixel(s, src);
			if (color != 0x000000)
				scale_pixel(d, color, scale, dst);
			s.x++;
			d.x += scale;
		}
		s.y++;
		d.y += scale;
	}
}

void	add_image(t_pos2d p, int scale, t_data *src, t_data *dst)
{
	t_pos2d			s;
	t_pos2d			d;
	unsigned int	color;

	if (!dst || !src || scale < 1)
		return ;
	s.y = 0;
	d.y = p.y;
	while (s.y < src->pxl_h)
	{
		s.x = 0;
		d.x = p.x;
		while (s.x < src->pxl_w)
		{
			color = get_pixel(s, src) + get_pixel(d, dst);
			if (color != 0x000000)
				scale_pixel(d, color, scale, dst);
			s.x++;
			d.x += scale;
		}
		s.y++;
		d.y += scale;
	}
}
