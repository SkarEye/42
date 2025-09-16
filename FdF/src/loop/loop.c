/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:53:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:59:39 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "structures.h"
#include "image.h"
#include "loop_helper.h"
#include "exit_utils.h"
#include <X11/keysym.h>
//sanity checks ??

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
