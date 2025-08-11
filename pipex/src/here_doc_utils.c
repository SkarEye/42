/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:28:27 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/11 11:14:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#define BUFFER_SIZE	128

#define HD_PROMPT		"heredoc>"

static ssize_t	get_line(char **ptr, t_pipex *pipex)
{
	char	*temp;
	size_t	buf_size;
	size_t	pos;
	char	c;
	ssize_t	r;

	if (!ptr)
		exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex); //change here
	buf_size = BUFFER_SIZE;
	*ptr = xmalloc(sizeof(char) * buf_size, ERR_LOC, pipex); //careful here
	pos = 0;
	r = read(0, &c, 1);
	while (r == 1)
	{
		if (pos > buf_size)
		{
			buf_size += BUFFER_SIZE;
			temp = malloc(sizeof(char) * buf_size);
			if (!temp)
			{
				free(*ptr);
				exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
			}
			ft_strlcpy(temp, *ptr, buf_size);
			free(*ptr);
			*ptr = temp;
		}
		(*ptr)[pos++] = c;
		if (c == '\n')
			r = 0;
		else
			r = read(0, &c, 1);
	}
	if (r == -1 || (r == 0 && pos == 0))
	{
		free(*ptr);
		*ptr = NULL;
		return (-1);
	}
	(*ptr)[pos] = '\0';
	return ((ssize_t)pos);
}

void	get_here_doc(const char *dlmt, t_pipex *pipex)
{
	int		pipe[2];
	char	*line;
	ssize_t	read;

	if (!dlmt || !pipex)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	xpipe(pipe, ERR_LOC, pipex);
	while ()
	{
		write(STDOUT_FILENO, HD_PROMPT, 9);
		read = get_line(&line);
		if (line[read - 1] == '\n')
			line[read - 1] == '\0';
		if (ft_strcmp(line, dlmt) == 0)
			exit; //while
		line[read - 1]= '\n'; // don't know about this
		if (write(pipe[1], line, read) == -1)
		{
			free(line);
			exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
		}
	}
	free(line);
	xclose(pipe[1], ERR_LOC, pipex);
	pipex->infile = pipe[0];
}
