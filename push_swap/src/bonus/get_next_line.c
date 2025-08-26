/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:26:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:43:24 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bonus/gnl_utils.h"

#define BUFFER_SIZE	128

static bool	buffer_to_stash(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
		temp = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(*stash, buffer);
		free(*stash);
	}
	if (!temp)
	{
		*stash = NULL;
		return (false);
	}
	else
	{
		*stash = temp;
		return (true);
	}
}

char	*read_to_stash(int fd, char *stash)
{
	char		*buffer;
	int			bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if ((!buffer_to_stash(&stash, buffer)))
			bytes_read = -1;
		else if (ft_strchr(stash, '\n'))
			bytes_read = 0;
		else
			bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(stash), NULL);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	line[i] = '\0';
	return (line);
}

void	update_stash(char **stash)
{
	char	*temp;
	int		i;

	if (!*stash)
		return ;
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	{
		temp = ft_strdup(*stash + i + 1);
		free(*stash);
		if (!temp)
		{
			*stash = NULL;
			return ;
		}
		*stash = temp;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash || !(ft_strchr(stash, '\n')))
	{
		stash = read_to_stash(fd, stash);
		if (!stash)
			return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	update_stash(&stash);
	return (line);
}
