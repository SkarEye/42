/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:44:07 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:49:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "so_long_params.h"
#include "structures.h"
#include "img_utils.h"
#include "img_pool_utils.h"
#include "text_utils.h"
#include "animate_utils.h"

#include "render_utils.h"

#include <stdio.h> //for debugging purposes
#include <unistd.h> //temp, for usleep

int render(void *param)
{
	t_game 	*game;

	usleep(33000);
	game = (t_game *)param;
	if (game->state == STATE_INIT)
		render_init(game);
	if (game->state == STATE_MENU)
	{
		clear_image(game->data);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->data->img, 0, 0);
	return (0);
}
