/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:19:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:37:00 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>

#include "structures.h"
#include "loop.h"
#include "image.h"
#include "utils.h"
#include "exit_utils.h"

#include <X11/X.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	if (argc != 2)
		return (exit_fdf(loc(F, L), ERR_BAD_ARGS, 1, &fdf), 1);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, PXL_W, PXL_H, "FdF");
	set_map(argv[1], &fdf);
	fdf.data = make_blank_image(fdf.mlx, PXL_W, PXL_H);
	fdf.font = get_image_from_xpm(fdf.mlx, "assets/BowAndArrow.xpm");
	set_vertical(&fdf);
	mlx_hook(fdf.win, KeyPress, KeyPressMask, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, handle_x, &fdf);
	mlx_loop_hook(fdf.mlx, render, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
