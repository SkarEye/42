/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:21:10 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/16 14:26:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"

#include <string.h>
#include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	double	angle;
}	t_vars;

void set_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_rotating_square(t_data *data, int center_x, int center_y, int size, double angle)
{
	usleep(33000);
	int x, y;
	int half_size = size / 2;
	double rad_angle = angle * (3.14159265358979323846 / 180.0);
	int color = 0x00FF00;
	for (y = -half_size; y < half_size; y++)
	{
		for (x = -half_size; x < half_size; x++)
		{
			int rotated_x = (int)(x * cos(rad_angle) - y * sin(rad_angle)) + center_x;
			int rotated_y = (int)(x * sin(rad_angle) + y * cos(rad_angle)) + center_y;
			set_pixel(data, rotated_x, rotated_y, color);
		}
	}
}

int render_frame(void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	bzero(vars->data.addr, 800 * 600 * (vars->data.bits_per_pixel / 8));
	draw_rotating_square(&vars->data, 400, 300, 100, vars->angle);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	vars->angle += 1.0;
	if (vars->angle >= 360.0)
		vars->angle = 0.0;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello World");
	if (!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.data.img = mlx_new_image(vars.mlx, 800, 600);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel,
			&vars.data.line_length, &vars.data.endian);
	vars.angle = 0.0;
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}