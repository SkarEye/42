/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/15 11:36:44 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "projections.h"

#include <X11/keysym.h>

#define PRESS_SPACE "- PRESS SPACE -"
int	render_start(t_fdf *fdf)
{
	t_txt	txt;
	int		s;

	s = 2;
	txt = set_txt((t_pos2d){PXL_W, G_W * s}, 0xFFBB00, s, A_CENTERED);
	draw_text(PRESS_SPACE, (t_pos2d){0, PXL_H / 2 - (G_H * s) / 2}, txt, fdf);
	return (0);
}

int	handle_start(int key, t_fdf *fdf)
{
	if (key == XK_space)
		fdf->state = FDF;
	return (0);
}
