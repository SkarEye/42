/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:53:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/03 20:02:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

int	render(t_fdf *fdf)
{
	clear_image(fdf->data);
	if (fdf->state == START)
		render_start(fdf);
	if (fdf->state == MENU)
		render_menu(fdf);
	if (fdf->state == FDF)
		render_fdf(fdf);
	if (fdf->state == PAUSE)
		render_pause(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	return (0);
}