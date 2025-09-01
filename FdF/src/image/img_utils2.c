/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:09:25 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/01 15:08:29 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	paste_image(t_pixel p, int scale, t_data *src, t_data *dst)
{
	t_pixel	s;
	t_pixel	d;
	
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
			get_pixel(s, src);
			if (s.color != 0x000000)
				scale_pixel(d, scale, dst);
			s.x++;
			d.x += scale;
		}
		s.y++;
		d.y += scale;
	}
}

void	outline_image(int size, unsigned int color, t_data *img)
{
	t_pixel	p;

	if (!img || size < 1)
		return ;
	p.color = color;
	p.y = 0;
	while (p.y < img->pxl_h)
	{
		p.x = 0;
		while (p.x < img->pxl_w)
		{
			if ((p.x < size || p.x > img->pxl_w - size)
				&& (p.y < size || p.y > img->pxl_h - size))
				set_pixel(p, img);
			p.x++;
		}
		p.y++;
	}
}
