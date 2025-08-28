/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:31:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 13:34:45 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "structures.h"
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

//idk
// int	xopen(int *fd, const char *filename, int flags, t_debug dbg, t_fdf *fdf)
// {
// 	*fd = open(filename, flags);
// 	if (*fd == -1)
// 		exit_fdf(dbg, ERR_PERROR, 1, fdf);
// 	return (*fd);
// }

void	xclose(int *fd, t_debug dbg, t_fdf *fdf)
{
	if (*fd >= 0)
	{
		if (close(*fd) == -1)
			exit_fdf(dbg, ERR_PERROR, 1, fdf);
		*fd = -1;
	}
}
