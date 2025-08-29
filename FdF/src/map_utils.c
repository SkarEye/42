/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:37:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/29 14:39:25 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "structures.h"
#include "utils.h"
#include "get_next_line.h"
#include "exit_utils.h"

void	free_map(int **map, size_t height)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	allocate_map(size_t width, size_t height, t_fdf *fdf)
{
	int	**map;
	size_t	i;

	map = xmalloc(sizeof(int *) * height, loc(F, L), fdf);
	i = 0;
	while (i < height)
	{
		map[i] = xmalloc(sizeof(int) * width, loc(F, L), fdf);
		i++;
	}
	fdf->map = map;
}

void	get_map_size(const char *filename, t_fdf *fdf)
{
	int		fd;
	size_t	line_len;

	if (filename == NULL)
		exit_fdf(loc(F, L), ERR_NO_FILENAME, 1, fdf);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_fdf(loc(F, L), ERR_OPEN, 1, fdf);
	fdf->map_h = 0;
	line_len = get_next_line(fd, fdf);
	fdf->map_w = line_len;
	while (line_len > 0)
	{
		if (fdf->map_w != line_len)
			exit_fdf(loc(F, L), ERR_READ, 1, fdf);
		fdf->map_h++;
		line_len = get_next_line(fd, fdf);
	}
	xclose(&fd, loc(F, L), fdf);
	if (!fdf->map_w || !fdf->map_h)
		exit_fdf(loc(F, L), ERR_INVALID_MAP, 1, fdf);

}

void	get_map(const char *filename, t_fdf *fdf)
{
	int		fd;
	size_t	i;
	size_t	j;
	

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_fdf(loc(F, L), ERR_OPEN, 1, fdf);
	allocate_map(fdf->map_w, fdf->map_h, fdf);
	get_map_size(filename, fdf);
	i = 0;
	j = 0;
	while (i < fdf->map_h)
	{
		j = 0;
		while (j < fdf->map_w)
		{
			fdf->map[i][j] = ft_atoi(fdf->line);
			free(fdf->line);
			fdf->line = NULL;
			j++;
		}
		i++;
	}