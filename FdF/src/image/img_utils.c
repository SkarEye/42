/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:58:15 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "exit_utils.h"

void	clear_image(t_data *img)
{
	ft_bzero(img->addr, img->pxl_w * img->pxl_h * (img->bits_pxl / 8));
}

void	free_image(void *mlx, t_data *data)
{
	if (!data)
		return ;
	if (mlx && data->img)
		mlx_destroy_image(mlx, data->img);
	xfree(data);
}

t_data	*make_blank_image(void *mlx, int width, int height)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = mlx_new_image(mlx, width, height);
	if (!data->img)
		return (xfree(data), NULL);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_pxl, &data->line_length, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(mlx, data->img);
		return (xfree(data), NULL);
	}
	data->pxl_w = width;
	data->pxl_h = height;
	clear_image(data);
	return (data);
}

//error handling ?
t_data	*get_image_from_xpm(void *mlx, char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		return (NULL);
	}
	data->img = mlx_xpm_file_to_image(mlx, file, &data->pxl_w, &data->pxl_h);
	if (!data->img)
		return (xfree(data), NULL);
	data->addr = mlx_get_data_addr(data->img, &data->bits_pxl,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (free_image(mlx, data), NULL);
	return (data);
}
