/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:20:12 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 20:56:35 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"

size_t	get_space_count(const char *str, size_t max_len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < max_len && str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

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
		if (i + word_len <= max_len)
			i += word_len;
		else
			return (i);
	}
	return (i);
}

size_t	get_pixel_offset(const char *str, t_txt txt)
{
	size_t	pixel_offset;

	if (txt.align == A_LEFT || txt.align == A_JUSTIFIED)
		return (0);
	pixel_offset = txt.size.x - get_line_len(str, txt.size.x / (G_W * txt.scale)) * G_W * txt.scale;
	if (txt.align == A_RIGHT)
		return (pixel_offset);
	if (txt.align == A_CENTERED)
		return (pixel_offset / 2);
	else
		return (0);
}
