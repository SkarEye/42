/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:42:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "projections.h"

#include <X11/keysym.h>

#define TITLE		"- FDF -"
#define PRESS_SPACE "> PRESS SPACE <"

/**
 * @brief Handles key presses when in 'start' state.
 *
 * @param key Keypress value
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	handle_start(int key, t_fdf *fdf)
{
	if (key == XK_space)
		fdf->state = FDF;
	return (0);
}

/**
 * @brief Renders 'start' state.
 *
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	render_start(t_fdf *fdf)
{
	t_txt	txt;

	txt = set_txt((t_pos2d){PXL_W, G_W * 12}, 0xFFBB00, 12, A_CENTERED);
	draw_text(TITLE, (t_pos2d){0, PXL_H / 2 - (G_H * 12) / 2}, txt, fdf);
	txt = set_txt((t_pos2d){PXL_W, G_W * 3}, 0xFFBB00, 3, A_CENTERED);
	draw_text(PRESS_SPACE, (t_pos2d){0, 3 * PXL_H / 4 - (G_H * 3) / 2}, txt, fdf);
	return (0);
}
