/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:05 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/09 11:32:27 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
    char	*str;
    size_t	i;
    size_t	j;
    size_t	len;

    if (!s1 || !set)
        return (NULL);
    i = 0;
    while (s1[i] && ft_strchr(set, s1[i]))
        i++;
    j = ft_strlen(s1);
    while (j > i && ft_strchr(set, s1[j - 1]))
        j--;
    len = j - i;
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1 + i, len + 1);
    return (str);
}