/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/11 19:48:44 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 

#include "structures.h"
#include "utils.h"
#include "get_next_line.h"
#include "exec_utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#define HERE_DOC	"here_doc"

#define HD_PROMPT		"heredoc>"

void	get_here_doc(const char *lmt, t_pipex *pipex)
{
	int		pipe[2];
	size_t	line_len;

	if (!lmt || !pipex)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	xpipe(pipe, ERR_LOC, pipex);
	line_len = 1;
	while (line_len)
	{
		write(STDOUT_FILENO, HD_PROMPT, 9);
		line_len = get_next_line(0, pipex);
		if (line_len > 0 && pipex->line[line_len - 1] == '\n')
			pipex->line[line_len - 1] = '\0';
		if (ft_strcmp(pipex->line, lmt) == 0)
			line_len = 0;
		else
			pipex->line[line_len - 1] = '\n';
		if (line_len > 0 && write(pipe[1], pipex->line, line_len) == -1)
			exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
		free(pipex->line);
	}
	xclose(&pipe[1], ERR_LOC, pipex);
	pipex->infile = pipe[0];
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	pipex = xcalloc(sizeof(t_pipex), ERR_LOC, pipex);
	if (argc < 5)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	if (!envp || !*envp)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex); //other exit_code ?
	if (ft_strncmp(argv[1], HERE_DOC, 9) == 0)
	{
		if (argc < 6)
			exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
		get_here_doc(argv[2], pipex); // set limiter (first arg)
	}
	else
	pipex->infile = xopen(argv[1], O_RDONLY, 0, ERR_LOC, pipex);
	pipex->out_path = argv[argc - 1];
	pipex->n_cmds = argc - 3;
	pipex->cmds = ft_strtabndup(&argv[2], pipex->n_cmds);
	if (!pipex->cmds)
		exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
	pipex->envp = envp;
	exec_cmds(pipex);
	free_pipex(pipex);
	return (0);
}
