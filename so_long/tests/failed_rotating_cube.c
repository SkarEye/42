/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:21:10 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/16 16:46:57 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	double	angle;
}	t_vars;

typedef struct s_point3d
{
	double x;
	double y;
	double z;
}	t_point3d;

typedef struct s_point2d
{
	int x;
	int y;
}	t_point2d;

void set_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= 800 || y < 0 || y >= 600)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_point3d rotate_x(t_point3d point, double angle)
{
	t_point3d rotated;

	double rad_angle = angle * (3.14159265358979323846 / 180.0);
	rotated.x = point.x;
	rotated.y = point.y * cos(rad_angle) - point.z * sin(rad_angle);
	rotated.z = point.y * sin(rad_angle) + point.z * cos(rad_angle);
	return (rotated);
}

t_point3d rotate_y(t_point3d point, double angle)
{
	t_point3d rotated;

	double rad_angle = angle * (3.14159265358979323846 / 180.0);
	rotated.x = point.x * cos(rad_angle) - point.z * sin(rad_angle);
	rotated.y = point.y;
	rotated.z = -point.x * sin(rad_angle) + point.z * cos(rad_angle);
	return (rotated);
}

t_point3d rotate_z(t_point3d point, double angle)
{
	t_point3d rotated;

	double rad_angle = angle * (3.14159265358979323846 / 180.0);
	rotated.x = point.x * cos(rad_angle) - point.y * sin(rad_angle);
	rotated.y = point.x * sin(rad_angle) + point.y * cos(rad_angle);
	rotated.z = point.z;
	return (rotated);
}

t_point2d project(t_point3d point, int width, int height, double scale)
{
	t_point2d projected;

	if (point.z == 0)
		point.z = 0.0001f;

	projected.x = (int)(width / 2 + (point.x / point.z) * scale);
	projected.y = (int)(height / 2 + (point.y / point.z) * scale);
	return projected;
}

void	bresenham_line(t_data *data, t_point2d p0, t_point2d p1, int color)
{
	t_point2d dp;
	t_point2d ds;
	int err;

	dp.x = abs(p1.x - p0.x);
	dp.y = abs(p1.y - p0.y);
	ds.x = (p1.x < p0.x) ? -1 : 1;
	ds.y = (p1.y < p0.y) ? -1 : 1;
	err = dp.x - dp.y;
	int e2;

	while (1)
	{
		set_pixel(data, p0.x, p0.y, color);
		if (p1.x == p0.x && p1.y == p0.y)
			break;
		e2 = 2 * err;
		if (e2 > -dp.y)
		{
			err -= dp.y;
			p0.x += ds.x;
		}
		if (e2 < dp.x)
		{
			err += dp.x;
			p0.y += ds.y;
		}
	}
}

void draw_rotating_cube(t_data *data, t_point3d center, int size, double angle)
{
	int i;
	t_point3d cube[8];
	t_point2d projected[8];
	int edges[12][2] = {
	{0, 1}, {1, 2}, {2, 3}, {3, 0},
	{4, 5}, {5, 6}, {6, 7}, {7, 4},
	{0, 4}, {1, 5}, {2, 6}, {3, 7}
	};
	int half = size / 2;

	cube[0] = (t_point3d){center.x - half, center.y - half, center.z - half};
	cube[1] = (t_point3d){center.x + half, center.y - half, center.z - half};
	cube[2] = (t_point3d){center.x + half, center.y + half, center.z - half};
	cube[3] = (t_point3d){center.x - half, center.y + half, center.z - half};
	cube[4] = (t_point3d){center.x - half, center.y - half, center.z + half};
	cube[5] = (t_point3d){center.x + half, center.y - half, center.z + half};
	cube[6] = (t_point3d){center.x + half, center.y + half, center.z + half};
	cube[7] = (t_point3d){center.x - half, center.y + half, center.z + half};

	usleep(33000);
	for (i = 0; i < 8; i++)
	{
		//rotated = rotate_x(cube[i], angle);
		//rotated = rotate_y(rotated, angle);
		cube[i] = rotate_z(cube[i], angle);
		projected[i] = project(cube[i], 800, 600, 10);
	}
	for (i = 0; i < 12; i++)
	{
		bresenham_line(data, projected[edges[i][0]], projected[edges[i][1]], 0xFF4D00);
	}
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
	draw_rotating_cube(&vars->data, (t_point3d){400, 300, 100}, 250, vars->angle);
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
