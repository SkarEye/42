/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:07:39 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/21 15:25:38 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	is_map_border(t_coords *coords, t_map *map)
{
	if (coords->x == 0 || coords->x == map->width - 1
		|| coords->y == 0 || coords->y == map->height - 1)
		return (1);
	return (0);
}