/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:54 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 12:50:04 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = -2147483648;
	b = 2147483647;
	printf("%i, %i\n", a, b);
	ft_swap(&a, &b);
	printf("%i, %i\n", a, b);
	return (0);
}
*/