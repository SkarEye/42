/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:50:13 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:00:35 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "image.h"
#include "text_helper.h"

static t_pixel	get_glyph_position(char c)
{
	t_pixel	pos;

	if (c < ' ' && c != '\n')
		c = 63;
	c -= 32;
	pos.x = (c % FONT_ROW_SIZE) * G_W;
	pos.y = (c / FONT_ROW_SIZE) * G_H;
	return (pos);
}

static void	draw_glyph(char c, t_pixel p, t_txt txt, t_fdf *fdf)
{
	t_pixel	g;
	t_pixel	f;
	t_pixel	d;

	if (txt.scale < 1)
		return ;
	g = get_glyph_position(c);
	f.y = g.y;
	d.y = p.y;
	while (f.y < g.y + G_H)
	{
		f.x = g.x;
		d.x = p.x;
		while (f.x < g.x + G_W)
		{
			if (!get_pixel(f, fdf->font))
				scale_pixel(d, txt.color, txt.scale, fdf->data);
			f.x++;
			d.x += txt.scale;
		}
		f.y++;
		d.y += txt.scale;
	}
}

static size_t	draw_str(const char *str, t_pixel p, t_txt txt, t_fdf *fdf)
{
	size_t	count;
	size_t	leftover;
	size_t	line_len;
	size_t	i;

	line_len = get_line_len(str, txt.size.x / (G_W * txt.scale));
	count = get_space_count(str, line_len);
	leftover = txt.size.x - line_len * G_W * txt.scale;
	i = 0;
	while (i < line_len)
	{
		if (str[i] == ' ' && txt.align == A_JUSTIFIED && count > 0)
		{
			p.x += 	leftover / count;
			leftover -= leftover / count--;
		}
		draw_glyph(str[i], p, txt, fdf);
		p.x += G_W * txt.scale;
		i++;
	}
	return (line_len);
}

void	draw_text(const char *str, t_pixel p, t_txt txt, t_fdf *fdf)
{
	t_pixel	d;
	size_t	i;

	if (!str) //fdf checking?
		return ;
	d.x = p.x + get_pixel_offset(str, txt);
	d.y = p.y;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		else
			i += draw_str(&str[i], d, txt, fdf);
		d.x = p.x + get_pixel_offset(&str[i], txt);
		d.y += G_H * txt.scale;
		if (d.y > txt.size.y)
			return ;
	}
}
