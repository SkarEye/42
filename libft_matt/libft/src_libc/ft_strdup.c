/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:12:59 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/09 11:32:21 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *src)
{
        size_t    i;
        char    *dst;

        dst = (char *)malloc((ft_strlen(src) + 1) *(sizeof(char)));
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