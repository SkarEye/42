/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:58:49 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 14:06:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int n)
{
	if (n < 0 || n > 12)
		return (0);
	if (n == 1 || n == 0)
		return (1);
	return (n * ft_recursive_factorial(n - 1));
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
*/