/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:07:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/23 15:26:01 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	is_valid_text(const char *filename, size_t *height, size_t *width)
{
	char	*line;
	size_t	len;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, INVALID_READ, 20), 0);
	*height = 0;
	*width = 0;
	while (line = get_next_line(fd))
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		if (*height == 0)
			*width = len;
		else if (len != *width)
			return (free(line), close(fd), write(2, INVALID_TEXT_FILE, 55), 0);
		(*height)++;
		free(line);
	}
	return (close(fd), 1);
}

is_valid_coords(t_coords p, t_map *map)
{
	char	c;

	c = map->grid[p.y][p.x];
	if ((p.x == 0 || p.x == map->width - 1
		|| p.y == 0 || p.y == map->height - 1) && c != '1')
		return (0);
	if (c == 'P')
	{
		if (!map->player)
		{
			map->player = (t_coords *)malloc(sizeof(t_coords));
			if (!map->player)
				return (write(2, INVALID_MALLOC, 25), 0);
			*(map->player) = p;
		}
		else
			return (write(2, TOO_MANY_START_POS, 0), 0)
	}

	
}

char	is_valid_grid(t_map *map)
{
	t_coords	p;

	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (!is_valid_coords(p, map))
				return (0);
			p.x++;
		}
		p.y++;
	}
	return (1);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
	if (map->collectibles)
		free_list(map->collectibles);
	if (map->player)
		free(map->player);
	if (map->exit)
		free(map->exit);
	free(map);
}

char	create_map(const char *filename)
{
	t_map	*map;
	int		fd;
	size_t	i;

	if (!is_valid_text(filename, &map->height, &map->width))
		return (0);
	fd = open(filename, O_RDONLY); 
	if (fd < 0) // necessary ?
		return (write(2, INVALID_READ, 20), 0);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (close(fd), write(2, INVALID_MALLOC, 25), 0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (free_map(map), close(fd), write(2, INVALID_MALLOC, 25), 0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i++])
			return (free_map(map), close(fd), write(2, INVALID_MALLOC, 25), 0);
	}
	map->grid[i] = NULL;
	return (close(fd), 1);
}
