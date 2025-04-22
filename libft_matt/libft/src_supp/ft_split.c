/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:42:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/09 14:42:12 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
    size_t	count;
    size_t	i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

char    *ft_makeword(const char *s, char c)
{
    char    *word;
    size_t  len;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return (NULL);
    ft_strlcpy(word, s, len + 1);
    return (word);
}

void    ft_freesplit(char **split, size_t n)
{
    while (n-- > 0)
        free(split[n]);
    free(split);
}

char    **ft_split(char const *s, char c)
{
    char    **split;
    size_t n;
    size_t i;

    split = (char **)malloc((ft_countwords( s, c) + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    n = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            split[n] = ft_makeword((char *)&s[i], c);
            if (!(split[n]))
            {
                ft_freesplit(split, n);
                return (NULL);
            }
            i += ft_strlen(split[n++]);
        }
    }
    split[n] = NULL;
    return (split);
}

