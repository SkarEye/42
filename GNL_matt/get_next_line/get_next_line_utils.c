/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:46:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/23 19:19:07 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = (dst > src) * (n - 1);
	while (n--)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i += (dst < src) - (dst > src);
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1 && s1[len_s1])
		len_s1++;
	while (s2 && s2[len_s2])
		len_s2++;
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}
