/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 13:14:48 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> //for b_zero, to be rm-ed

#include <stdlib.h>
#include "mlx.h"
#include "so_long_params.h"
#include "structures.h"

#include "img_utils.h"

void	clear_image(t_data *img)
{
	bzero(img->addr, img->p_w * img->p_h * (img->bits_pxl / 8)); //to be modded
}

void	free_image(void *mlx, t_data *data)
{
	if (!data)
		return ;
	if (mlx && data->img)
		mlx_destroy_image(mlx, data->img);
	free(data);
}

t_data *make_blank_image(void *mlx, int width, int height)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);

	data->img = mlx_new_image(mlx, width, height);
	if (!data->img)
		return (free(data), NULL);

	data->addr = mlx_get_data_addr(data->img,
		&data->bits_pxl, &data->line_length, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(mlx, data->img);
		return (free(data), NULL);
	}

	data->p_w = width;
	data->p_h = height;
	return (data);
}

t_data	*get_image_from_xpm(void *mlx, char *filename)
{
	t_data	*data;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		return (NULL); //Error handling here ?
	}
	data->img = mlx_xpm_file_to_image(mlx, filename, &data->p_w, &data->p_h);
	if (!data->img)
		return (free(data), NULL);
	data->addr = mlx_get_data_addr(data->img, &data->bits_pxl,
		&data->line_length, &data->endian);
	if (!data->addr)
		return (free_image(mlx, data), NULL);
	return (data);
}
