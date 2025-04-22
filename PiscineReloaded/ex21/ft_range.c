/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:47:54 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 16:21:40 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (max <= min)
		return (NULL);
	range = (int *)malloc((max - min) * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	*range;
	int	i;
	int	size;

	if (argc == 3)
	{
		range = ft_range(atoi(argv[1]), atoi(argv[2]));
		if (!range)
			return (1);
		i = 0;
		size = atoi(argv[2]) - atoi(argv[1]);
		while (i < size)
			printf("%i\n", range[i++]);
		free(range);
		return (0);
	}
	return (1);
}
*/