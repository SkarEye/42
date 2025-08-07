/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabndup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:58:15 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/07 17:26:09 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "utils.h"


char	**ft_strtabndup(char **srctab, size_t n)
{
	char 	**dsttab;
	size_t	i;

	if (!srctab || !*srctab)
		return (NULL); 
	i = 0;
	while (srctab[i])
		i++;
	if (n == 0)
		return (NULL);
	else if (i < n)
		n = i;
	dsttab = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dsttab)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dsttab[i] = ft_strdup(srctab[i]);
		if (!dsttab[i])
			return (ft_free_strtab(dsttab), NULL);
		i++;
	}
	dsttab[i] = NULL;
	return (dsttab);
}
