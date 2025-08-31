/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:21:10 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 09:33:40 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <so_long_params.h>
#include "structures.h"
#include "img_utils.h"
#include "img_pool_utils.h"
#include "text_utils.h"
#include "render_utils.h"
#include "exit_utils.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define TEST_STR "La poire William est delicieuse, MMMMMMMMMMMMMMMMMMM"

int	handle_key(int keycode, void *param)
{
	t_game *game = (t_game *)param;

	printf("Keycode : %d\n", keycode);
	if (keycode == 65307) // Escape
		exit_game(ERR_NONE, NULL, game);
	if (game->state == STATE_START)
	{
		if (keycode == 32) // Space key
			game->state = STATE_MENU;
	}
	return (0);
}

int	init_game_pool(t_game *game)
{
	t_data	*data;
	t_text_info *txt_i;

	game->pool = init_image_pool();
	if (!game->pool)
		return (0);
	data = get_image_from_xpm(game->mlx, "./assets/fonts/Scribe.xpm");
	put_image_in_pool(game->mlx, game->pool, IMG_FONT, data);
	data = get_image_from_xpm(game->mlx, "./assets/fonts/claire.xpm");
	put_image_in_pool(game->mlx, game->pool, IMG_CLAIRE, data);
	txt_i = set_text_info(200, 200, 0xffff00, A_LEFT);
	data = text_to_image(game->mlx, game->pool[IMG_FONT], TEST_STR, txt_i);
	scale_image(game->mlx, &data, 3);
	put_image_in_pool(game->mlx, game->pool, IMG_INIT_PARAGRAPH, data);
	txt_i->color = 0x00aa00;
	data = text_to_image(game->mlx, game->pool[IMG_FONT], TEST_STR, txt_i);
	scale_image(game->mlx, &data, 2);
	put_image_in_pool(game->mlx, game->pool, IMG_INIT_PAR2, data);
	free(txt_i);
	return (1);
}

int	main(void)
{
	t_game game;
	
	game.p_w = PXL_W;
	game.p_h = PXL_H;
	game.state = STATE_START;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.p_w, game.p_h, "Chess Scape");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	game.data = make_blank_image(game.mlx, PXL_W, PXL_H);
	game.base = make_blank_image(game.mlx, PXL_W, PXL_H);
	if (!game.data || !game.base)
		return (1);
	init_game_pool(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
