/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:50:25 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/24 15:20:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

int	main(int argc, char **argv)
{
	unsigned int	n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	printf("n = %i\nitoa gives = %s\nhex = %x\nitoh gives = %s\n", n, ft_itoa(n, '-'), n, ft_itoh(n, 0, 'A'));
	printf("%+09d\n", 12345678);
	printf("%+.9d\n", 12345678);
	return (0);
}