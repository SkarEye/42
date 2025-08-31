/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:19:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/31 17:04:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "map_utils.h"
#include "projections.h"

void	render(t_fdf *fdf)
{
	size_t	i;
	size_t	j;
	t_pixel	a;
	t_pixel	b;

	mlx_clear_window(fdf->mlx, fdf->win);
	for (j = 0; j < fdf->map_h; j++)
	{
		for (i = 0; i < fdf->map_w; i++)
		{
			if (i + 1 < fdf->map_w)
			{
				a = project(fdf->map[j * fdf->map_w + i], fdf);
				b = project(fdf->map[j * fdf->map_w + i + 1], fdf);
				bresenham_line(a, b, fdf);
			}
			if (j + 1 < fdf->map_h)
			{
				a = project(fdf->map[j * fdf->map_w + i], fdf);
				b = project(fdf->map[(j + 1) * fdf->map_w + i], fdf);
				bresenham_line(a, b, fdf);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1); //error handling?
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, PXL_W, PXL_H, "FdF");
	set_map(argv[1], &fdf);
	

	mlx_loop_hook(fdf.mlx, render, &fdf);
	mlx_loop(fdf.mlx);
	return 0;
}
