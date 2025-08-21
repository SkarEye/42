/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:44:07 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/08 15:00:03 by macarnie         ###   ########.fr       */
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
#include "render_helper.h"

#include "render_utils.h"

#include <stdio.h> //for debugging purposes
#include <unistd.h> //temp, for usleep

int render(void *param)
{
	t_game 	*game;

	usleep(33000);
	game = (t_game *)param;
	paste_image(game->data, game->pool[IMG_CLAIRE], 0, 0);
	if (game->alpha < 1.0)
	{
		fade_in(game, game->pool[IMG_INIT_PARAGRAPH], 50, 150, game->alpha);
		game->alpha += 0.01;
	}
	// if (game->state == STATE_INIT)
	// 	paste_image(game->data, game->pool[IMG_FONT], 0, 0);
	// 	//render_init(game);
	// if (game->state == STATE_START)
	// {
	// 	paste_image(game->pool[IMG_FONT], game->data, 0, 0);
	// }
	printf("%i\n", game->state);
	mlx_put_image_to_window(game->mlx, game->win, game->data->img, 0, 0);
	return (0);
}
