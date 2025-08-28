/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:37:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 14:43:27 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	**allocate_map(size_t width, size_t height, t_debug dbg, t_fdf *fdf)
{
	int	**map;
	size_t	i;

	map = xmalloc(sizeof(int *) * height, dbg, fdf);
	i = 0;
	while (i < height)
	{
		map[i] = xmalloc(sizeof(int) * width, dbg, fdf);
		i++;
	}
	return (map);
}

void	get_map_size(const char *filename, t_fdf *fdf)
{
	int		fd;

	if (filename == NULL)
		exit_fdf(loc(F, L), ERR_NO_FILENAME, 1, fdf);
	fd = -1;
	// xopen(&fd, filename, O_RDONLY, loc(__FILE__, __LINE__), fdf); --- IGNORE ---
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_fdf(loc(F, L), ERR_OPEN, 1, fdf);
	fdf->map_h = 0;
	fdf->map_w = get_next_line(fd, fdf);
	while (fdf->map_w > 0)
	{
		else if (fdf->map_w != fdf->map_h)
			exit_fdf(loc(F, L), ERR_NOT_RECT, 1, fdf);
		fdf->map_h++;
	}
	xclose(&fd, loc(FI, __LINE__), fdf);
	if (height == 0)
		exit_fdf(loc(F, L), ERR_INVALID_MAP, 1, fdf);

}
