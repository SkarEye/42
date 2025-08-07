/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:16:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/07 19:24:41 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"

#include "exit_wrappers.h"

void	*xmalloc(size_t size, t_debug dbg, t_pipex *p)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_current(dbg, ERR_PERROR, 1, p);
	return (ptr);
}

void	*xcalloc(size_t size, t_debug dbg, t_pipex *p)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_current(dbg, ERR_PERROR, 1, p);
	ft_bzero(ptr, size);
	return (ptr);
}

int		xopen(const char *path, int flg, mode_t mode, t_debug dbg, t_pipex *p)
{
	int	fd;

	fd = open(path, flg, mode);
	if (fd == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
	return (fd);
}

void	xclose(int *fd, t_debug dbg, t_pipex *p)
{
	if (*fd >= 0)
	{
		if (close(*fd) == -1)
			exit_current(dbg, ERR_PERROR, 1, p);
		*fd = -1;
	}
}
