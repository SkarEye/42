/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:20:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/11 17:04:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#define BUFFER_SIZE	128

static bool	buffer_to_stash(char *buf, t_pipex *pipex)
{
	char *	temp;
	
	if (!pipex->stash)
	{
		pipex->stash = ft_strdup(buf);
		if (!pipex->stash)
			return (false);
	}
	else
	{
		temp = ft_join(pipex->stash, buf, "");
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
	char	*temp;
	int		bytes_read;
	
	buf = xmalloc(sizeof(char) * (BUFFER_SIZE + 1), ERR_LOC, pipex);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!buffer_to_stash(buf, pipex))
		{
			free(buf);
			exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
		}
		if (ft_strchr(pipex->stash, '\n'))
			bytes_read = 0;
		else
			bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read == -1)
		exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
}

static char	*extract_line(t_pipex *pipex)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	while (pipex->stash[i] && pipex->stash[i] != '\n')
		i++;
	if (pipex->stash[i] == '\n')
		i++;
	line = xmalloc((sizeof(char)) * (i + 1), ERR_LOC, pipex);
	ft_strlcpy(line, pipex->stash, i);
	if (pipex->stash[i] == '\n')
	{
		temp = ft_strdup(pipex->stash + i);
		if (!temp)
			exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
		free(pipex->stash);
		pipex->stash = temp;
	}
	else
	{
		free(pipex->stash);
		pipex->stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd, t_pipex *pipex)
{
	char		*line;

	if (!pipex->stash || !ft_strchr(pipex->stash, '\n'))
		read_to_stash(fd, pipex);
	line = extract_line(pipex);
	return (line);
}
