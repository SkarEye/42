/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:16:15 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/07 17:25:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

#include "structures.h"
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

int		xopen(const char *path, int flg, mode_t mode, t_debug dbg, t_pipex *p)
{
	int	fd;

	fd = open(path, flg, mode);
	if (fd == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
	return (fd);
}

void	xclose(int fd, t_debug dbg, t_pipex *p)
{
	if (close(fd) == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
}
