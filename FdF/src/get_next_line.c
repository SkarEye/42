/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:20:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 13:39:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"

#define BUFFER_SIZE	128

static bool	buffer_to_stash(char *buf, t_fdf *fdf)
{
	char	*temp;

	if (!fdf->stash)
	{
		fdf->stash = ft_strdup(buf);
		if (!fdf->stash)
			return (false);
	}
	else
	{
		temp = ft_join(fdf->stash, buf, '\0');
		free(fdf->stash);
		if (!temp)
			return (false);
		fdf->stash = temp;
	}
	return (true);
}

static void	read_to_stash(int fd, t_fdf *fdf)
{
	char	*buf;
	int		bytes_read;

	buf = xmalloc(sizeof(char) * (BUFFER_SIZE + 1), loc(F, L), fdf);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!buffer_to_stash(buf, fdf))
		{
			free(buf);
			exit_fdf(loc(F, L), ERR_PERROR, 1, fdf);
		}
		if (ft_strchr(fdf->stash, '\n'))
			bytes_read = 0;
		else
			bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read == -1)
		exit_fdf(loc(F, L), ERR_PERROR, 1, fdf);
}

static size_t	extract_line(t_fdf *fdf)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (fdf->stash[i] && fdf->stash[i] != '\n')
		i++;
	if (fdf->stash[i] == '\n')
		i++;
	fdf->line = xmalloc((sizeof(char)) * (i + 1), loc(F, L), fdf);
	ft_strlcpy(fdf->line, fdf->stash, i);
	if (fdf->stash[i])
	{
		temp = ft_strdup(fdf->stash + i);
		if (!temp)
			exit_fdf(loc(F, L), ERR_PERROR, 1, fdf);
		free(fdf->stash);
		fdf->stash = temp;
	}
	else
	{
		free(fdf->stash);
		fdf->stash = NULL;
	}
	return (i);
}

size_t	get_next_line(int fd, t_fdf *fdf)
{
	if (!fdf->stash || !ft_strchr(fdf->stash, '\n'))
		read_to_stash(fd, fdf);
	return (extract_line(fdf));
}
