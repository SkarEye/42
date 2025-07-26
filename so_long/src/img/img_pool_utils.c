/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pool_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:56:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 13:11:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "structures.h"
#include "img_utils.h"

#include "img_pool_utils.h"

t_data	**init_image_pool(void)
{
	t_data **pool;
	size_t	i;

	pool = (t_data **)malloc(IMG_POOL_END * sizeof (t_data *));
	if (!pool)
		return (NULL);
	i = 0;
	while (i < IMG_POOL_END)
		pool[i++] = NULL;
	return (pool);
}

bool	put_image_in_pool(void *mlx, t_data **pool, t_img_id id, t_data *img)
{
	if (!pool || !img || id >= IMG_POOL_END)
		return (false); //error handling ?
	if (pool[id])
		delete_image_from_pool(mlx, pool, id);
	pool[id] = img;
	return (true);
}

void	delete_image_from_pool(void *mlx, t_data **pool, t_img_id id)
{
	if (mlx && pool && id < IMG_POOL_END && pool[id])
	{
		free_image(mlx, pool[id]);
		pool[id] = NULL;
	}
}

t_data	*get_image_from_pool(t_data **pool, t_img_id id)
{
	if (!pool || id >= IMG_POOL_END)
		return (NULL);
	return (pool[id]);
}

void	free_image_pool(void *mlx, t_data **pool)
{
	t_img_id	id;

	id = 0;
	while (id < IMG_POOL_END)
		delete_image_from_pool(mlx, pool, id++);
	free(pool);
}
