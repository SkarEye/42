/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:26:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 16:16:16 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE	128

static void	free_stash(char *stash)
{
	if (stash)
		free(stash);
	stash = NULL;
}

static bool	buffer_to_stash(char *stash, char *buffer)
{
	char	*temp;

	if (!stash)
		temp = ft_strdup(buffer, "");
	else
	{
		temp = ft_strjoin(stash, buffer);
		free_stash(stash);
	}
	if (!temp)
		return (false);
	else
	{
		*stash = temp;
		return (true);
	}
}

static char	*read_to_stash(int fd, char *stash)
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
		return (free_stash(stash), NULL);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i);
	if (stash[i])
	{
		temp = ft_strdup(stash + i);
		free_stash(stash);
		if (!temp)
			return (free(line), NULL);
		stash = temp;
	}
	else
		free_stash(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash || !(ft_strchr(stash, '\n')))
	{
		read_to_stash(fd, stash);
		if (!stash)
			return (NULL);
	}
	line = extract_line(stash);
	if (!line)
		return (free_stash(stash), NULL);
	return (line);
}
