/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:36:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/23 18:15:46 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest == source || n == 0)
		return (dst);
	if (dest < source)
	{
		while (n--)
			*dest++ = *source++;
	}
	else
	{
		dest += n;
		source += n;
		while (n--)
			*(--dest) = *(--source);
	}
	return (dst);
}
