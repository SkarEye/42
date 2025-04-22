/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:57:37 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 14:22:15 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int n)
{
	int	fact;

	if (n < 0 || n > 12)
		return (0);
	fact = 1;
	while (n > 1)
		fact = fact * n--;
	return (fact);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_iterative_factorial(atoi(argv[1])));
	return (0);
}
*/