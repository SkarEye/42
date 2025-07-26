/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pool_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:56:44 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/25 15:16:36 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_POOL_UTILS_H
# define IMG_POOL_UTILS_H

# include <stdbool.h>
# include "structures.h"

t_data	**init_image_pool(void);
bool	put_image_in_pool(void *mlx, t_data **pool, t_img_id id, t_data *img);
void	delete_image_from_pool(void *mlx, t_data **pool, t_img_id id);
t_data	*get_image_from_pool(t_data **pool, t_img_id id);
void	free_image_pool(void *mlx, t_data **pool);

#endif
