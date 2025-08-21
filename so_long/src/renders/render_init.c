/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:47:28 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/05 14:45:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "animate_utils.h"
#include "img_utils.h"

#include "render_helper.h"

void	render_init(t_game *game)
{
	if (game->alpha < 1.0)
	{
		fade_in(game, game->pool[IMG_INIT_PARAGRAPH], 100, 200, game->alpha);
		game->alpha += 0.02;
	}
	else
		paste_image(game->data, game->pool[IMG_INIT_PARAGRAPH], 100, 200);
}
