/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:20:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 17:31:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#include "get_next_line.h"

#define BUFFER_SIZE	128

static bool	buffer_to_stash(char *buf, t_pipex *pipex)
{
	char	*temp;

	if (!pipex->stash)
	{
		pipex->stash = ft_strdup(buf);
		if (!pipex->stash)
			return (false);
	}
	else
	{
		temp = ft_join(pipex->stash, buf, '\0');
		free(pipex->stash);
		if (!temp)
			return (false);
		pipex->stash = temp;
	}
	return (true);
}

static void	read_to_stash(int fd, t_pipex *pipex)
{
	char	*buf;
	int		bytes_read;

	buf = xmalloc(sizeof(char) * (BUFFER_SIZE + 1), loc(F, L), pipex);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!buffer_to_stash(buf, pipex))
		{
			free(buf);
			exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
		}
		if (ft_strchr(pipex->stash, '\n'))
			bytes_read = 0;
		else
			bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read == -1)
		exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
}

static size_t	extract_line(t_pipex *pipex)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (pipex->stash[i] && pipex->stash[i] != '\n')
		i++;
	if (pipex->stash[i] == '\n')
		i++;
	pipex->line = xmalloc((sizeof(char)) * (i + 1), loc(F, L), pipex);
	ft_strlcpy(pipex->line, pipex->stash, i);
	if (pipex->stash[i] == '\n')
	{
		temp = ft_strdup(pipex->stash + i);
		if (!temp)
			exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
		free(pipex->stash);
		pipex->stash = temp;
	}
	else
	{
		free(pipex->stash);
		pipex->stash = NULL;
	}
	return (i);
}

size_t	get_next_line(int fd, t_pipex *pipex)
{
	if (!pipex->stash || !ft_strchr(pipex->stash, '\n'))
		read_to_stash(fd, pipex);
	return (extract_line(pipex));
}
