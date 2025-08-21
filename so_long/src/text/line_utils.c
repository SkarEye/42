/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:20:12 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/07 21:33:00 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "structures.h"
#include "text_utils.h"

#include "line_utils.h"

size_t	get_word_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

size_t	get_line_len(const char *str, size_t max_len)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			i++;
		word_len = get_word_len(&str[i]);
		if (word_len + i <= max_len)
			i += word_len;
		else
			return (i);
	}
	return (i);
}

size_t	get_pixel_offset(const char *str, t_text_info *txt_i)
{
	size_t	pixel_offset;

	pixel_offset = txt_i->width - get_line_len(str, txt_i->width) * GLYPH_WIDTH;
	if (txt_i->align == A_RIGHT)
		return (pixel_offset);
	if (txt_i->align == A_CENTERED)
		return (pixel_offset / 2);
	else
		return (0);
}
