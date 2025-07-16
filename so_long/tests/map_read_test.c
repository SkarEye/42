/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:06:54 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/11 17:24:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map_utils.h"
#include "exit_utils.h"

#define SYS_MAIN "main"

int main(int argc, char **argv)
{
	t_map	*map;
	size_t	i;

	i = 0;
	if (argc != 2)
		return (print_error(ERR_UNKNOWN, SYS_MAIN), EXIT_FAILURE);
	map = create_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	while (i < map->height)
	{
		write(1, map->grid[i], map->width);
		write(1, "\n", 1);
		i++;
	}
	free_map(map);
	return (EXIT_SUCCESS);
}
