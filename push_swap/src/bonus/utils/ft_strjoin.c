/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:52:50 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:51 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "bonus/gnl_utils.h"

char	*ft_strjoin(const char *first, const char *last)
{
	char	*join;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!first || !last)
		return (NULL);
	len = ft_strlen(first) + ft_strlen(last);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (first[j])
		join[i++] = first[j++];
	j = 0;
	while (last[j])
		join[i++] = last[j++];
	join[i] = '\0';
	return (join);
}
