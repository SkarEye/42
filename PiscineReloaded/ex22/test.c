/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:18:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 16:22:25 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_abs.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ABS(atoi(argv[1])));
	return (0);
}
