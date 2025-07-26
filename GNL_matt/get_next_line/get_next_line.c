/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:17:37 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/23 19:18:18 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	buffer_to_stash(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
		temp = ft_strjoin(buffer, "");
	else
	{
		temp = ft_strjoin(*stash, buffer);
		free(*stash);
	}
	if (!temp)
	{
		*stash = NULL;
		return (0);
	}
	else
	{
		*stash = temp;
		return (1);
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
	{
		free(stash);
		return (NULL);
	}
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
	ft_memmove(line, stash, i);
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
		temp = ft_strjoin(*stash + i + 1, "");
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
