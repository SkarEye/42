/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/20 17:10:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 

#include "structures.h"
#include "exec_utils.h"
#include "utils.h"
#include "get_next_line.h"
#include "exit_wrappers.h"
#include "error_utils.h"
#include "exit_utils.h"

#define DEV_NULL	"/dev/null"

#define HERE_DOC	"here_doc"

#define HD_PROMPT	"here_doc>"

static void	get_here_doc(t_pipex *pipex)
{
	int		pipe[2];
	size_t	line_len;

	if (!pipex || !pipex->lmt)
		exit_pipex(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	xpipe(pipe, loc(F, L), pipex);
	line_len = 1;
	while (line_len)
	{
		write(STDOUT_FILENO, HD_PROMPT, 9);
		line_len = get_next_line(0, pipex);
		if (line_len > 0 && pipex->line[line_len - 1] == '\n')
			pipex->line[line_len - 1] = '\0';
		if (ft_strcmp(pipex->line, pipex->lmt) == 0)
			line_len = 0;
		else
			pipex->line[line_len - 1] = '\n';
		if (line_len > 0 && write(pipe[1], pipex->line, line_len) == -1)
			exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
		free(pipex->line);
		pipex->line = NULL;
	}
	xclose(&pipe[1], loc(F, L), pipex);
	pipex->infile = pipe[0];
}

static void	setup_with_infile(int argc, char **argv, t_pipex *pipex)
{
	if (access(argv[1], R_OK) == 0)
		pipex->infile = open(argv[1], O_RDONLY, 0, loc(F, L), pipex);
	else
	{
		print_error(loc(F, L), ERR_NO_PATH, false);
		pipex->infile = open(DEV_NULL, O_RDONLY, 0, loc(F, L), pipex);
	}
	if (!pipex->infile)
		exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
	pipex->is_here_doc = false;
	pipex->outpath = argv[argc - 1];
	pipex->n_cmds = argc - 3;
	pipex->cmds = ft_strtabndup(&argv[2], pipex->n_cmds);
	if (!pipex->cmds)
		exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
}

static void	setup_with_here_doc(int argc, char **argv, t_pipex *pipex)
{
	pipex->lmt = argv[2];
	get_here_doc(pipex);
	pipex->is_here_doc = true;
	pipex->outpath = argv[argc - 1];
	pipex->n_cmds = argc - 4;
	pipex->cmds = ft_strtabndup(&argv[3], pipex->n_cmds);
	if (!pipex->cmds)
		exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		int_code;

	pipex = NULL;
	if (argc < 5)
		exit_pipex(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	if (!envp || !*envp)
		exit_pipex(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	pipex = xcalloc(sizeof(t_pipex), loc(F, L), pipex);
	if (ft_strncmp(argv[1], HERE_DOC, 9) == 0)
	{
		if (argc < 6)
			exit_pipex(loc(F, L), ERR_BAD_ARGS, 1, pipex);
		setup_with_here_doc(argc, argv, pipex);
	}
	else
		setup_with_infile(argc, argv, pipex);
	pipex->envp = envp;
	int_code = exec_cmds(pipex);
	free_pipex(pipex);
	return (int_code);
}
