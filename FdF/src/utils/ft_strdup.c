/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:15:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 19:47:26 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Duplicates a given character string to new a new address.
 *
 * @param str Character string to duplicate
 * @return Character address of duplicated string.
 */
char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dst;

	dst = (char *)malloc((ft_strlen(src) + 1) * (sizeof(char)));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
