/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:29:52 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/07 18:54:57 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
    size_t	i;
    unsigned char	*str;

    str = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        str[i] = 0;
        i++;
    }
    return (s);
}