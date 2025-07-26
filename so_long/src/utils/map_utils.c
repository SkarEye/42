/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:07:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 12:54:54 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structures.h"
#include "get_next_line.h"
#include "list_utils.h"
#include "exit_utils.h"
#include "map_utils.h"

#define SYS_IVTF "is_valid_text_file"
#define SYS_CG "create_grid"
#define SYS_CM "create_map"
#define SYS_VM "is_valid_map"

#define FLAG_PLAYER 0x01
#define FLAG_EXIT 0x02
#define FLAG_COLLECTIBLE 0x04

// to be removed
static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

bool	is_valid_text_file(const char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(ERR_OPEN, SYS_IVTF), false);
	while ((line = get_next_line(fd)))
	{
		if (map->width == 0)
			map->width = ft_strlen(line);
		else if ((int)ft_strlen(line) != map->width)
		{
			free(line);
			return (print_error(ERR_NOT_RECT, SYS_IVTF), close(fd), false);
		}
		map->height++;
		free(line);
	}
	return (true);
}

bool	create_grid(const char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(ERR_OPEN, SYS_CG), false);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (print_error(ERR_MALLOC, SYS_CG), close(fd), false);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error(ERR_READ, SYS_CG), close(fd), false);
		map->grid[i] = line;
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	return (true);
}


bool	is_valid_map(t_map *map)
{
	t_coords	pos;
	t_coords	*pos_copy;
	char		cell;
	char		flags;

	pos.x = 0;
	pos.y = 0;
	flags = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			cell = map->grid[pos.y][pos.x];
			if ((pos.x == 0 || pos.x == map->width - 1
				|| pos.y == 0 || pos.y == map->height - 1) && cell != '1')
				return (print_error(ERR_INVALID_WALLS, SYS_VM), false);
			if (cell == 'P')
			{
				if (flags & FLAG_PLAYER)
					return (print_error(ERR_TOO_MANY_PLAYERS, SYS_VM), false);
				flags |= FLAG_PLAYER;
				map->player.x = pos.x;
				map->player.y = pos.y;
			}
			else if (cell == 'E')
			{
				if (flags & FLAG_EXIT)
					return (print_error(ERR_TOO_MANY_EXITS, SYS_VM), false);
				flags |= FLAG_EXIT;
				map->exit.x = pos.x;
				map->exit.y = pos.y;
			}
			else if (cell == 'C')
			{
				flags |= FLAG_COLLECTIBLE;
				pos_copy = malloc(sizeof(t_coords));
				if (!pos_copy)
					return (print_error(ERR_MALLOC, SYS_VM), false);
				*pos_copy = pos;
				if (!add_to_list(&map->collectibles, pos_copy))
					return (print_error(ERR_MALLOC, SYS_VM), free(pos_copy), false);
			}
			else if (cell != '1' && cell != '0')
				return (print_error(ERR_INVALID_CHAR, SYS_VM), false);
			pos.x++;
		}
		pos.y++;
	}
	if (!(flags & FLAG_PLAYER))
		return (print_error(ERR_NO_PLAYER, SYS_VM), false);
	if (!(flags & FLAG_EXIT))
		return (print_error(ERR_NO_EXIT, SYS_VM), false);
	if (!(flags & FLAG_COLLECTIBLE))
		return (print_error(ERR_NO_COLLECTIBLES, SYS_VM), false);
	return (true);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
	free_list(&map->collectibles);
	free(map);
}

t_map		*create_map(const char *filename)
{
	t_map	*map;

	if (!filename)
		return (print_error(ERR_NO_FILENAME, SYS_CM), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (print_error(ERR_MALLOC, SYS_CM), NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->collectibles = NULL;
	if (!is_valid_text_file(filename, map))
		return (free_map(map), NULL);
	if (!create_grid(filename, map))
		return (free_map(map), NULL);
	if (!is_valid_map(map))
		return (free_map(map), NULL);
	return (map);
}
