/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/07 19:25:39 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "path_utils.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#include "exec_utils.h"

static void	exec_cmd(int n, t_pipex *pipex)
{
	pipex->cmd_args = ft_split(pipex->cmds[n], ' ');
	if (!pipex->cmd_args || !pipex->cmd_args[0])
		exit_child(ERR_LOC, ERR_PERROR, 1, pipex);
	get_cmd_path(pipex);
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->envp) == -1)
		exit_child(ERR_LOC, ERR_BAD_EXECVE, 126, pipex);
}

#include <stdio.h>
#include <fcntl.h>

static void	setup_child(int n, t_pipex *pipex)
{
	dprintf(2, "child alive\n");
	if (n == 0)
	{
		xdup2(pipex->infile, STDIN_FILENO, ERR_LOC, pipex);
		xclose(&pipex->infile, ERR_LOC, pipex);
	}
	else
		xdup2(pipex->prev_pipe[0], STDIN_FILENO, ERR_LOC, pipex);
	if (n == pipex->n_cmds - 1)
	{
		xdup2(pipex->outfile, STDOUT_FILENO, ERR_LOC, pipex);
		xclose(&pipex->outfile, ERR_LOC, pipex);
	}
	else
		xdup2(pipex->pipe[1], STDOUT_FILENO, ERR_LOC, pipex);
	xclose(&pipex->pipe[0], ERR_LOC, pipex);
	xclose(&pipex->pipe[1], ERR_LOC, pipex);
	if (n != 0)
	{
		xclose(&pipex->prev_pipe[0], ERR_LOC, pipex);
		xclose(&pipex->prev_pipe[1], ERR_LOC, pipex);
	}
}


static void	spawn_child(int n, t_pipex *pipex)
{
	xpipe(pipex->pipe, ERR_LOC, pipex);
	pipex->pids[n] = xfork(ERR_LOC, pipex);
	if (pipex->pids[n] == 0)
	{
		setup_child(n, pipex);
		exec_cmd(n, pipex);
	}
	else
	{
		if (n != 0)
		{
			xclose(&pipex->prev_pipe[0], ERR_LOC, pipex);
			xclose(&pipex->prev_pipe[1], ERR_LOC, pipex);
		}
		xclose(&pipex->pipe[1], ERR_LOC, pipex);
		pipex->prev_pipe[0] = pipex->pipe[0];
		pipex->prev_pipe[1] = pipex->pipe[1];
	}
	pipex->is_child = false;
}

void	exec_cmds(t_pipex *pipex)
{
	int	i;
	int	status;

	get_paths(pipex);
	pipex->pids = xmalloc((sizeof(pid_t) * pipex->n_cmds), ERR_LOC, pipex);
	i = 0;
	while (pipex->cmds[i])
		spawn_child(i++, pipex);
	xclose(&pipex->prev_pipe[0], ERR_LOC, pipex);
	xclose(&pipex->infile, ERR_LOC, pipex);
	xclose(&pipex->outfile, ERR_LOC, pipex);
	i = 0;
	while (i < pipex->n_cmds)
		xwaitpid(pipex->pids[i++], &status, 0, ERR_LOC, pipex);
}
