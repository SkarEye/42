/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:37:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/31 17:02:36 by macarnie         ###   ########.fr       */
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

void	set_point(int x, int y, const char *str, t_fdf *fdf)
{
	char	*comma;
	size_t	pos;

	pos = y * fdf->map_w + x;
	fdf->map[pos].x = x;
	fdf->map[pos].y = y;
	fdf->map[pos].z = ft_atoi(str);
	comma = ft_strchr(str, ',');
	if (comma)
		fdf->map[pos].color = ft_atoh(comma + 1);
	else
		fdf->map[pos].color = 0xFFFFFF;
}

t_point	get_point(int x, int y, t_fdf *fdf)
{
	if (x < 0 || x >= (int)fdf->map_w || y < 0 || y >= (int)fdf->map_h)
		return ((t_point){0, 0, 0, 0, 0, 0});
	return (fdf->map[y * fdf->map_w + x]);
}

void	set_map(const char *filename, t_fdf *fdf)
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
			set_point(i, j, split[i], fdf);
			i++;
		}
		ft_free_strtab(split);
		xfree(&fdf->line);
		j++;
	}
	xfree(&fdf->stash);
	xclose(&fd, loc(F, L), fdf);
}
