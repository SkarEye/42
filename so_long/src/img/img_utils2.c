/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:09:25 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 17:07:13 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_utils.h"

void	paste_image(t_data *dst, t_data *src, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;
	if (!dst || !src)
		return ;
	j = 0;
	while (j < src->p_h)
	{
		i = 0;
		while (i < src->p_w)
		{
			color = get_pixel_color(src, i, j);
			if (color != 0x000000)
				set_pixel_color(dst, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	scale_image(void *mlx, t_data **img, int scale)
{
	int 			i;
	int 			j;
	unsigned int	color;
	t_data 			*new_img;

	new_img = make_blank_image(mlx, (*img)->p_w * scale, (*img)->p_h * scale);
	if (!new_img)
		return ;
	j = 0;
	while (j < (*img)->p_h)
	{
		i = 0;
		while (i < (*img)->p_w)
		{
			color = get_pixel_color(*img, i, j);
			if (color != 0x000000)
				scale_pixel(new_img, i * scale, j * scale, color, scale);
			i++;
		}
	j++;
	}
	free_image(mlx, *img);
	*img = new_img;
}

void	outline_image(t_data *img, int size, unsigned int color)
{
	int 			i;
	int 			j;

	if (!img)
		return ;
	j = 0;
	while (j < img->p_h)
	{
		i = 0;
		while (i < img->p_w)
		{
			if ((i < size || i > img->p_w - size)
				&& (j < size || j > img->p_h - size))
				set_pixel_color(img, i, j, color);
			i++;
		}
		j++;
	}
}
