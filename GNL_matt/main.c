/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:38:27 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/02 18:23:59 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	size_t	count;

	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		else
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	count = 1;
	while (line)
	{
		printf("Count : %zu.\nLine : %s\n", count++, line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		return (1);
	return (0);
}