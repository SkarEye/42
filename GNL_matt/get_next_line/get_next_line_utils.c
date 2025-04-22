/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:46:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/14 08:07:59 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    *ft_memmove(void *dst, const void *src, size_t n)
{
    char    *d;
    const char  *s;

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    if (d == s || n == 0)
        return (dst);
    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    else
    {
        d += n;
        s += n;
        while (n--)
            *(--d) = *(--s);
    }
    return (dst);
}

void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    char    *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);
    if (ptr)
    {
        if (old_size < new_size)
            ft_memmove(new_ptr, ptr, old_size);
        else
            ft_memmove(new_ptr, ptr, new_size);
        free(ptr);
    }
    return (new_ptr);
}