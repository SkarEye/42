/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:19:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/15 15:31:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>

#include "structures.h"
#include "loop.h"
#include "image.h"

#include <stdio.h> // for debugging
#include "utils.h" //for ft_bzero
#include "math_helper.h"

#include <X11/X.h> //for key_loop

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1); //Tell how to write fdf exec with params
	ft_bzero(&fdf, sizeof(fdf));
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, PXL_W, PXL_H, "FdF");
	set_map(argv[1], &fdf);
	fdf.base = make_blank_image(fdf.mlx, PXL_W, PXL_H);
	fdf.data = make_blank_image(fdf.mlx, PXL_W, PXL_H);
	fdf.font = get_image_from_xpm(fdf.mlx, "assets/Scribe.xpm");
	set_vertical(&fdf);
	mlx_hook(fdf.win, KeyPress, KeyPressMask, handle_key, &fdf);
	mlx_loop_hook(fdf.mlx, render, &fdf);
	mlx_loop(fdf.mlx);
	return 0;
}
