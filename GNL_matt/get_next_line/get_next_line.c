/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:15:07 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/23 19:11:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		// write a better function to join stash and buf for all possibilities
		if (!stash)
			stash = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(stash, buf);
			free(stash);
			stash = temp;
		}
		if (ft_strchr(buf, '\n'))
			bytes_read = 0;
		else
			bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	// could use memcpy here
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_stash(char *stash, size_t i)
{
	char	*temp;
	size_t	j;

	if (!stash || !*stash)
		// free stash ?
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		(stash)[j] = (stash)[i + j];
		j++;
	}
	stash[j] = '\0';
	temp = ft_strdup(stash);
	free(stash);
	if (!temp)
		return (NULL);
	else
		return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(stash[fd], '\n'))
	{
		stash[fd] = read_to_stash(fd, stash[fd]);
		if (!stash[fd])
			return (NULL);
	}
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
