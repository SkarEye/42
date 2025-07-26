/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:34:19 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:41:31 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structures.h"
#include "img_utils.h"

#include "animate_utils.h"

void	fade_in(t_game *game, t_data *img, int x, int y, double alpha)
{
	int	i;
	int	j;
	unsigned int	src_color;
	unsigned int	img_color;
	unsigned int	blend;

	if ( !game || !game->data || !game->base || !img)
		return ;
	j = 0;
	while (j < img->p_h)
	{
		i = 0;
		while (i < img->p_w)
		{
			img_color = get_pixel_color(img, i , j);
			if (img_color != 0x000000)
			{
				src_color = get_pixel_color(game->base, x + i, y + j);
				blend = blend_colors(src_color, img_color, alpha);
				set_pixel_color(game->data, x + i, y + j, blend);
			}
			i++;
		}
		j++;
	}
}
