/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:11:31 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 19:58:07 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "utils.h"

/**
 * @brief Copies at most size bytes of a character string into a buffer.
 *
 * @param src Character string to copy from
 * @param dst Character buffer to copy into
 * @param size Maximum amount of bytes copied
 * @return Size of src
 * @note Copies either length of src or size, whichever is smaller.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
