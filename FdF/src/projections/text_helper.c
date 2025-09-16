/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:20:12 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:11:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"

/**
 * @brief Calculates the amount of spaces in a string.
 *
 * @param str Character string
 * @param max_len Maximum length to parse
 * @return Amount of spaces in str
 * @note Count ends when either max_len or end of string is reached,
 * whichever comes first
 */
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

/**
 * @brief Calculates the length of a word in a string.
 *
 * @param str Character string
 * @return Word length.
 */
size_t	get_word_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

/**
 * @brief Calculates the length of a line in a string.
 *
 * @param str Character string
 * @param max_len Maximum line length
 * @return Line length.
 * @note The calculation doesn't truncate words, unless the first word in line
 * is bigger than the maximum length.
 */
size_t	get_line_len(const char *str, size_t max_len)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	word_len = get_word_len(str);
	if (word_len > max_len)
		return (max_len);
	i += word_len;
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

/**
 * @brief Gets the offset of the current line given the text parameters.
 *
 * @param str Character string
 * @param txt Text parameters
 * @return The offset value of the given line.
 */
size_t	get_pixel_offset(const char *str, t_txt txt)
{
	size_t	line_len;
	size_t	pixel_offset;

	if (txt.align == A_LEFT || txt.align == A_JUSTIFIED)
		return (0);
	line_len = get_line_len(str, txt.size.x / (G_W * txt.scale));
	pixel_offset = txt.size.x - line_len * G_W * txt.scale;
	if (txt.align == A_RIGHT)
		return (pixel_offset);
	if (txt.align == A_CENTERED)
		return (pixel_offset / 2);
	else
		return (0);
}
