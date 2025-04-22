/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:34:00 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/07 16:00:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t    i;
    unsigned char    *str_dest;
    const unsigned char    *str_src;

    str_dest = (unsigned char *)dest;
    str_src = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        str_dest[i] = str_src[i];
        i++;
    }
    return (dest);
}