/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:15:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:59:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

char	*ft_join(const char *first, const char *last, char c)
{
	char	*join;
	ssize_t	len;
	size_t	i;
	size_t	j;

	if (!first || !last)
		return (NULL);
	len = ft_strlen(first) + ft_strlen(last);
	if (c)
		len++;
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (first[j])
		join[i++] = first[j++];
	if (c)
		join[i++] = c;
	j = 0;
	while (last[j])
		join[i++] = last[j++];
	join[i] = '\0';
	return (join);
}
