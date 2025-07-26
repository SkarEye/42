/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:50:13 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 13:32:16 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "mlx.h"
#include "so_long_params.h"
#include "structures.h"
#include "line_utils.h"
#include "img_utils.h"

#include "text_utils.h"

t_text_info	*set_text_info(int w, int h, int color, t_align align)
{
	t_text_info *txt_i;

	txt_i = (t_text_info *)malloc(sizeof(t_text_info));
	if (!txt_i)
		return (NULL);
	txt_i->width = w;
	txt_i->height = h;
	txt_i->color = color;
	txt_i->align = align;
	return (txt_i);
	
}

t_coords	get_glyph_position(char c)
{
	t_coords	pos;
	
	if (c < ' ' && c != '\n')
		c = 63;
	c -= 32;
	pos.x = (c % FONT_ROW_SIZE) * GLYPH_WIDTH;
	pos.y = (c / FONT_ROW_SIZE) * GLYPH_HEIGHT;
	return (pos);
}

void	draw_char(t_data *dst, t_data *font, char c,
		t_coords pos, t_text_info *txt_i)
{
	t_coords		glyph_pos;
	size_t			i;
	size_t			j;
	unsigned int	color;

	glyph_pos = get_glyph_position(c);
	i = 0;
	j = 0;
	while (j < GLYPH_HEIGHT)
	{
		while (i < GLYPH_WIDTH)
		{
			color = get_pixel_color(font, glyph_pos.x + i, glyph_pos.y + j);
			if (color != 0x000000)
				set_pixel_color(dst, pos.x + i, pos.y + j, txt_i->color);
			i++;
		}
		i = 0;
		j++;
	}

}

size_t	draw_string(t_data *dst, t_data *font, const char *str,
		t_coords pos, t_text_info *txt_i)
{
	t_coords	char_pos;
	size_t		i;
	size_t		line_len;
	
	char_pos = pos;
	i = 0;
	line_len = get_line_len(str, txt_i->width / GLYPH_WIDTH);
	while (i < line_len)
	{
		draw_char(dst, font, str[i], char_pos, txt_i);
		char_pos.x += GLYPH_WIDTH;
		i++;
	}
	return (i);
}

t_data	*text_to_image(void *mlx, t_data *font, const char *str,
		t_text_info *txt_i)
{
	t_data		*txt_img;
	size_t		i;
	t_coords	str_pos;

	if (!str || !txt_i)
		return (NULL);
	txt_img = make_blank_image(mlx, txt_i->width, txt_i->height);
	if (!txt_img)
		return (NULL);
	i = 0;
	str_pos.x = get_pixel_offset(&str[i], txt_i);
	str_pos.y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		else
			i += draw_string(txt_img, font, &str[i], str_pos, txt_i);
		str_pos.x = get_pixel_offset(&str[i], txt_i);
		str_pos.y += GLYPH_HEIGHT;
	}
	return (txt_img);
}
