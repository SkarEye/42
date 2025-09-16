/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:45:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:23:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <X11/keysym.h>

#include "structures.h"
#include "projections.h"
#include "math_helper.h"

#define MOVE_SPEED	0.01f
#define ROT_SPEED	0.001f
#define ZOOM_SPEED	0.05f
#define FISH_SPEED	0.0005f
#define FRICTION	0.995f

static void	handle_pos_inertia(int key, t_fdf *fdf)
{
	if (key == XK_a)
	{
		fdf->inertia.v.x -= cosf(fdf->cam.r.y) * MOVE_SPEED;
		fdf->inertia.v.z -= sinf(fdf->cam.r.y) * MOVE_SPEED;
	}
	if (key == XK_s)
	{
		fdf->inertia.v.x += cosf(fdf->cam.r.y + PI / 2) * MOVE_SPEED;
		fdf->inertia.v.z += sinf(fdf->cam.r.y + PI / 2) * MOVE_SPEED;
	}
	if (key == XK_d)
	{
		fdf->inertia.v.x += cosf(fdf->cam.r.y) * MOVE_SPEED;
		fdf->inertia.v.z += sinf(fdf->cam.r.y) * MOVE_SPEED;
	}
	if (key == XK_w)
	{
		fdf->inertia.v.x += cosf(fdf->cam.r.y - PI / 2) * MOVE_SPEED;
		fdf->inertia.v.z += sinf(fdf->cam.r.y - PI / 2) * MOVE_SPEED;
	}
	if (key == XK_space)
		fdf->inertia.v.y += MOVE_SPEED;
	if (key == XK_Shift_L)
		fdf->inertia.v.y -= MOVE_SPEED;
}

static void	handle_ang_inertia(int key, t_fdf *fdf)
{
	if (key == XK_Up)
		fdf->inertia.r.x += ROT_SPEED;
	if (key == XK_Down)
		fdf->inertia.r.x -= ROT_SPEED;
	if (key == XK_Left)
		fdf->inertia.r.y -= ROT_SPEED;
	if (key == XK_Right)
		fdf->inertia.r.y += ROT_SPEED;
	if (key == XK_q)
		fdf->inertia.r.z -= ROT_SPEED;
	if (key == XK_e)
		fdf->inertia.r.z += ROT_SPEED;
}

static void	apply_inertia(t_fdf *fdf)
{
	fdf->cam.v.x += fdf->inertia.v.x;
	fdf->cam.v.y += fdf->inertia.v.y;
	fdf->cam.v.z += fdf->inertia.v.z;
	fdf->cam.r.x += fdf->inertia.r.x;
	fdf->cam.r.y += fdf->inertia.r.y;
	fdf->cam.r.z += fdf->inertia.r.z;
	if (fdf->cam.fov < 0)
		fdf->cam.fov = 0;
	else if (fdf->cam.fov > 180)
		fdf->cam.fov = 180;
	else
		fdf->cam.fov += fdf->inertia.fov;
	fdf->cam.r.x = normalize_angle(fdf->cam.r.x);
	fdf->cam.r.y = normalize_angle(fdf->cam.r.y);
	fdf->cam.r.z = normalize_angle(fdf->cam.r.z);
	fdf->inertia.v.x *= FRICTION;
	fdf->inertia.v.y *= FRICTION;
	fdf->inertia.v.z *= FRICTION;
	fdf->inertia.r.x *= FRICTION;
	fdf->inertia.r.y *= FRICTION;
	fdf->inertia.r.z *= FRICTION;
	fdf->inertia.fov *= FRICTION;
}

/**
 * @brief Handles key presses when drawing the wireframe.
 *
 * @param key Keypress value
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	handle_fdf(int key, t_fdf *fdf)
{
	handle_pos_inertia(key, fdf);
	handle_ang_inertia(key, fdf);
	if (key == XK_Insert)
		fdf->inertia.fov += ZOOM_SPEED;
	if (key == XK_Delete)
		fdf->inertia.fov -= ZOOM_SPEED;
	if (key == XK_F1 && !fdf->cam.is_fish)
		fdf->cam.is_fish = true;
	else if (key == XK_F1)
		fdf->cam.is_fish = false;
	if (key == XK_F2 && !fdf->cam.is_3d)
		fdf->cam.is_3d = true;
	else if (key == XK_F2)
		fdf->cam.is_3d = false;
	if (key == XK_F5)
		set_vertical(fdf);
	if (key == XK_F6)
		set_horizontal(fdf);
	if (key == XK_F7)
		set_isometric(fdf);
	return (0);
}

/**
 * @brief Renders the wireframe and addons.
 *
 * @param fdf FDF pointer
 * @return 0 for MLX loop.
 */
int	render_fdf(t_fdf *fdf)
{
	apply_inertia(fdf);
	fdf->cam.focal = (0.5 * PXL_W) / tanf(rad(fdf->cam.fov) / 2.0);
	get_matrix(&fdf->cam);
	if (fdf->cam.is_3d)
		draw_3d(fdf);
	else
		draw_fdf(fdf->cam, 0, fdf);
	draw_gyroscope((t_pos2d){10, 10}, 50, fdf);
	return (0);
}
