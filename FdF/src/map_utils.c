/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:37:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/30 13:59:16 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "structures.h"
#include "utils.h"
#include "get_next_line.h"
#include "exit_utils.h"

static void	get_map_size(const char *filename, t_fdf *fdf)
{
	int		fd;
	size_t	arg_count;

	if (filename == NULL)
		exit_fdf(loc(F, L), ERR_NO_FILENAME, 1, fdf);
	fd = xopen(filename, O_RDONLY, loc(F, L), fdf);
	fdf->map_h = 0;
	fdf->map_w = 0;
	while (get_next_line(fd, fdf))
	{
		arg_count = ft_countwords(fdf->line, ' ');
		if (fdf->map_w == 0)
			fdf->map_w = arg_count;
		else if (arg_count != fdf->map_w)
			exit_fdf(loc(F, L), ERR_INVALID_MAP, 1, fdf);
		fdf->map_h++;
		xfree(&fdf->line);
	}
	xfree(&fdf->stash);
	xclose(&fd, loc(F, L), fdf);
	if (!fdf->map_w || !fdf->map_h)
		exit_fdf(loc(F, L), ERR_INVALID_MAP, 1, fdf);
}

static t_point	set_point(int x, int y, const char *str)
{
	t_point	point;
	char	*comma;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	comma = ft_strchr(str, ',');
	if (comma)
		point.color = ft_atoh(comma + 1);
	else
		point.color = 0xFFFFFF;
	return (point);
}

t_point	get_point(int x, int y, t_fdf *fdf)
{
	if (x < 0 || x >= (int)fdf->map_w || y < 0 || y >= (int)fdf->map_h)
		return ((t_point){0, 0, 0, 0, 0, 0});
	return (fdf->map[y * fdf->map_w + x]);
}

void	get_map(const char *filename, t_fdf *fdf)
{
	int		fd;
	char	**split;

	size_t	i;
	size_t	j;
	
	get_map_size(filename, fdf);
	fdf->map = xcalloc(sizeof(t_point) * (fdf->map_h * fdf->map_w), loc(F, L), fdf);
	fd = xopen(filename, O_RDONLY, loc(F, L), fdf);
	j = 0;
	while (get_next_line(fd, fdf))
	{
		split = xsplit(fdf->line, ' ');
		i = 0;
		while (split[i])
		{
			fdf->map[j * fdf->map_w + i] = set_point(i, j, split[j]);
			i++;
		}
		ft_free_strtab(split);
		xfree(&fdf->line);
		j++;
	}
	xfree(&fdf->stash);
	xclose(&fd, loc(F, L), fdf);
}
