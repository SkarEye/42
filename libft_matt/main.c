/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:43:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/23 18:29:08 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    size_t  count;

	if (argc != 3)
	{
		printf("Usage: %s <string> <delimiter>\n", argv[0]);
		return (1);
	}
	if (argv[2][1] != '\0')
	{
		printf("Delimiter must be a single character\n");
		return (1);
	}
	count = ft_countwords(argv[1], argv[2][0]);
	printf("Number of words: %zu\n", count);

	char **result = ft_split("This is a test", ' ');
	if (!result)
	{
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}