/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:50:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:59 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	div;
	int	mod;
	if (argc == 3)
	{
		ft_div_mod(atoi(argv[1]), atoi(argv[2]), &div, &mod);
		printf("Div = %i, Mod = %i\n", div, mod);
	}
	return (0);
}
*/