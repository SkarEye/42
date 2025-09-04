/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:37:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 15:20:35 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "structures.h"
#include "utils.h"
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
		xfree(fdf->line);
	}
	xfree(fdf->stash);
	fdf->stash = NULL;
	xclose(&fd, loc(F, L), fdf);
	if (!fdf->map_w || !fdf->map_h)
		exit_fdf(loc(F, L), ERR_INVALID_MAP, 1, fdf);
}

size_t	get_pos(size_t x, size_t z, t_fdf *fdf)
{
	return (z * fdf->map_w + x);	
}

static void	set_point(int x, int z, const char *str, t_fdf *fdf)
{
	char	*comma;
	size_t	pos;

	pos = get_pos(x, z, fdf);
	fdf->map[pos].p.x = x;
	fdf->map[pos].p.y = ft_atoi(str);
	fdf->map[pos].p.z = z;
	comma = ft_strchr(str, ',');
	if (comma)
		fdf->map[pos].color = ft_htoui(comma + 1);
	else
		fdf->map[pos].color = 0xFFFFFF;
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
		split = xsplit(fdf->line, ' ', loc(F, L), fdf);
		i = 0;
		while (split[i])
		{
			set_point(i, j, split[i], fdf);
			i++;
		}
		ft_free_strtab(split);
		xfree(fdf->line);
		j++;
	}
	xfree(fdf->stash);
	fdf->stash = NULL;
	xclose(&fd, loc(F, L), fdf);
}
