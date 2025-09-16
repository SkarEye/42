/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:11:18 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:02:14 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "structures.h"
#include "exit_utils.h"

/**
 * @brief Wrapper function for 'open' that safely exits program on error.
 *
 * @param filename Filename to open
 * @param flags Access mode and file creation/status flags
 * @param dbg Filename and line value
 * @param fdf FDF struct pointer
 * @return A new (int) FD for the file
 */
int	xopen(const char *filename, int flags, t_debug dbg, t_fdf *fdf)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == -1)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (fd);
}

/**
 * @brief Wrapper function for 'close' that safely exits program on error.
 *
 * @param fd File FD to close
 * @param dbg Filename and line value
 * @param fdf FDF struct pointer
 * @note Never tries to open a negative FD.
 * @note Always sets the FD to -1 on successful close.
 */
void	xclose(int *fd, t_debug dbg, t_fdf *fdf)
{
	if (*fd >= 0)
	{
		if (close(*fd) == -1)
			exit_fdf(dbg, ERR_PERROR, 1, fdf);
		*fd = -1;
	}
}
