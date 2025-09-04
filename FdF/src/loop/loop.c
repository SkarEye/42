/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:53:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 17:34:39 by macarnie         ###   ########.fr       */
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
	// if (fdf->state == MENU)
	// 	render_menu(fdf);
	if (fdf->state == FDF)
		handle_fdf(key, fdf);
	// if (fdf->state == PAUSE)
	// 	render_pause(fdf);
	return (0);
}

#include <stdio.h> //to rm

int	render(t_fdf *fdf)
{
	printf("state : %i\n", fdf->state);
	clear_image(fdf->data);
	if (fdf->state == START)
		render_start(fdf);
	// if (fdf->state == MENU)
	// 	render_menu(fdf);
	if (fdf->state == FDF)
		render_fdf(fdf);
	// if (fdf->state == PAUSE)
	// 	render_pause(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	return (0);
}