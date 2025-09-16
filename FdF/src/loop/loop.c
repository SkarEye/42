/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:53:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:42:19 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "structures.h"
#include "image.h"
#include "loop_helper.h"
#include "exit_utils.h"
#include <X11/keysym.h>

/**
 * @brief Handles close button 'X' exit.
 *
 * @param key Keypress value
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	handle_x(t_fdf *fdf)
{
	exit_fdf(loc(F, L), ERR_NONE, 0, fdf);
	return (0);
}

/**
 * @brief Handles key presses during runtime.
 *
 * @param key Keypress value
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	handle_key(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		exit_fdf(loc(F, L), ERR_NONE, 0, fdf);
	if (fdf->state == START)
		handle_start(key, fdf);
	if (fdf->state == FDF)
		handle_fdf(key, fdf);
	return (0);
}

/**
 * @brief Renders current program state.
 *
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	render(t_fdf *fdf)
{
	clear_image(fdf->data);
	if (fdf->state == START)
		render_start(fdf);
	if (fdf->state == FDF)
		render_fdf(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	return (0);
}
