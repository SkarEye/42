/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:14:50 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/23 18:10:45 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return (1);
	}
	int number = atoi(argv[1]);
	char *result = ft_itoa(number);
	if (!result)
	{
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	printf("String representation of %d: %s\n", number, result);
	free(result);
	return (0);
}