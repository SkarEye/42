/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:31:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/01 14:03:09 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"

void	*xmalloc(size_t size, t_debug dbg, t_fdf *fdf)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (ptr);
}

void	*xcalloc(size_t size, t_debug dbg, t_fdf *fdf)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	ft_bzero(ptr, size);
	return (ptr);
}

char	**xsplit(const char *s, char c, t_debug dbg, t_fdf *fdf)
{
	char	**ptr;

	ptr = ft_split(s, c);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (ptr);
}

void	xfree(void *ptr)
{
	if (ptr)
		free(ptr);
}

int	xopen(const char *filename, int flags, t_debug dbg, t_fdf *fdf)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == -1)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (fd);
}

void	xclose(int *fd, t_debug dbg, t_fdf *fdf)
{
	if (*fd >= 0)
	{
		if (close(*fd) == -1)
			exit_fdf(dbg, ERR_PERROR, 1, fdf);
		*fd = -1;
	}
}
