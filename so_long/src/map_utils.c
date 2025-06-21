/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:07:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/21 15:55:23 by macarnie         ###   ########.fr       */
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
			return (free(line), close(fd), 0);
		(*height)++;
		free(line);
	}
	return (close(fd), 1);
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
			if (is_map_border(p, map) && map->grid[p.y][p.x] != '1')
				return (0);
			else if (map->grid[p.y][p.x] == 'P')
				map->player = p;
			else if (map->grid[p.y][p.x] == 'E')
				map->exit = p;
			else if (map->grid[p.y][p.x] == 'C')
			{
				// add to t_list collectibles
			}
			else if (map->grid[p.y][p.x] != '1' && map->grid[p.y][p.x] != '0')
				return (0);
			p.x++;
		}
		p.y++;
	}
	return (1);
}

void	free_grid(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
}

void	free_map(t_map *map)
{
	
}

char	create_grid(const char *filename, t_map *map)
{
	int		fd;
	size_t	i;

	if (!is_valid_text(filename, &map->height, &map->width))
		return (write(2, INVALID_TEXT_FILE, 55), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, INVALID_READ, 20), 0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (close(fd), write(2, INVALID_MALLOC, 25), 0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i++])
			return (close(fd), free_grid(map), write(2, INVALID_MALLOC, 25), 0);
	}
	map->grid[i] = NULL;
	return (close(fd), 1);
}
