/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:10:17 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/03 15:28:38 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "math_helper.h"

#include <X11/keysym.h>
#include <X11/X.h>

#define MOVE_SPEED 0.5
#define ROT_SPEED  0.05
#define ZOOM_SPEED 5.0

static void	handle_wasd(int key, t_fdf *fdf)
{
	double c_w;
	double s_w;

	if (key == XK_w)
	{
		fdf->cam.x += cos(fdf->cam.w) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.w) * MOVE_SPEED;
	}
	if (key == XK_s)
	{
		fdf->cam.x -= cos(fdf->cam.w) * MOVE_SPEED;
		fdf->cam.z -= sin(fdf->cam.w) * MOVE_SPEED;
	}
	if (key == XK_a)
	{
		fdf->cam.x += cos(fdf->cam.w + PI) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.w + PI) * MOVE_SPEED;
	}
	if (key == XK_d)
	{
		fdf->cam.x += cos(fdf->cam.w - PI) * MOVE_SPEED;
		fdf->cam.z += sin(fdf->cam.w - PI) * MOVE_SPEED;
	}
}

int	handle_key(int key, t_fdf *fdf)
{
	// handle quit
	handle_wasd(key, fdf);
	if (key == XK_q)
		fdf->cam.y += MOVE_SPEED;
	if (key == XK_e)
		fdf->cam.y -= MOVE_SPEED;
	if (key == XK_Left)
		fdf->cam.w -= ROT_SPEED;
	if (key == XK_Right)
		fdf->cam.w += ROT_SPEED;
	if (key == XK_Up)
		fdf->cam.u += ROT_SPEED;
	if (key == XK_Down)
		fdf->cam.u -= ROT_SPEED;
	if (key == XK_plus || key == XK_equal)
		fdf->cam.fov -= ZOOM_SPEED;
	if (key == XK_minus)
		fdf->cam.fov += ZOOM_SPEED;
	render(fdf);
	return (0);
}
