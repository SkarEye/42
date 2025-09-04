/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:13:28 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "image.h"

#include <X11/keysym.h>

#define PRESS_SPACE	"- PRESS SPACE -"

int	render_start(t_fdf *fdf)
{
	t_txt	txt;
	int		s;

	s = 4;
	txt = set_txt((t_pixel){PXL_W, G_W * s}, 0xFFBB00, s, A_CENTERED);
	draw_text(PRESS_SPACE, (t_pixel){0, PXL_H / 2 - (G_H * s) / 2}, txt, fdf);
	return (0);
}

int	handle_start(int key, t_fdf *fdf)
{
	if (key == XK_space)
		fdf->state = FDF;
	return (0);
}
