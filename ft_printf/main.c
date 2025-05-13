/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:50:25 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/12 14:34:35 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{

	printf("n = %i, n = %d, u = %u, x = %x, X = %X, c = %c, s = %s, %% = %%.\n",
		 1243, 21434, 400000000, 324215, 45245, 'c', "This is test");
	ft_printf("n = %i, n = %d, u = %u, x = %x, X = %X, c = %c, s = %s, %% = %%.\n",
		1243, 21434, 400000000, 324215, 45245, 'c', "This is test");
	/*
	printf("sThis is a test\n");
	ft_printf("This is a test\n");

	printf("s%%\n");
	ft_printf("%%\n");

	printf("s%s\n", "This is a third test");
	ft_printf("%s\n", "This is a third test");

	printf("sn = %x\n", 1234);
	ft_printf("n = %x\n", 1234);

	printf("sn = %X\n", 1234);
	ft_printf("n = %X\n", 1234);

	printf("sn = %i\n", 1234);
	ft_printf("n = %i\n", 1234);
	*/
	return (0);
}
