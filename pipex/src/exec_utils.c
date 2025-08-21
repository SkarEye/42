/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/21 19:40:36 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "structures.h"
#include "path_utils.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#include "exec_utils.h"

static void	exec_cmd(int n, t_pipex *p)
{
	p->cmd_args = ft_split(p->cmds[n], ' ');
	if (!p->cmd_args)
		exit_child(loc(F, L), ERR_PERROR, 1, p);
	if (!p->cmd_args[0])
		exit_child(loc(F, L), ERR_NO_CMD, 1, p);
	get_cmd_path(p);
	if (execve(p->cmd_path, p->cmd_args, p->envp) == -1)
		exit_child(loc(F, L), ERR_BAD_EXECVE, 126, p);
}

static void	setup_child(int n, t_pipex *p)
{
	if (n == 0)
		xdup2(p->io[0], STDIN_FILENO, loc(F, L), p);
	else
		xdup2(p->prev_pipe[0], STDIN_FILENO, loc(F, L), p);
	if (n == p->n_cmds - 1)
	{
		if (p->is_here_doc)
			p->io[1] = open(p->outpath, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			p->io[1] = open(p->outpath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->io[1] == -1)
			exit_child(loc(F, L), ERR_PERROR, 1, p);
		xdup2(p->io[1], STDOUT_FILENO, loc(F, L), p);
		xclose(&p->io[1], loc(F, L), p);
	}
	else
		xdup2(p->pipe[1], STDOUT_FILENO, loc(F, L), p);
	xclose(&p->pipe[0], loc(F, L), p);
	xclose(&p->pipe[1], loc(F, L), p);
	if (n != 0)
	{
		xclose(&p->prev_pipe[0], loc(F, L), p);
		xclose(&p->prev_pipe[1], loc(F, L), p);
	}
}

static void	spawn_child(int n, t_pipex *p)
{
	xpipe(p->pipe, loc(F, L), p);
	p->pids[n] = xfork(loc(F, L), p);
	if (p->pids[n] == 0)
	{
		setup_child(n, p);
		exec_cmd(n, p);
	}
	else
	{
		if (p->is_here_doc)
			xclose(&p->io[0], loc(F, L), p);
		if (n != 0)
		{
			xclose(&p->prev_pipe[0], loc(F, L), p);
			xclose(&p->prev_pipe[1], loc(F, L), p);
		}
		xclose(&p->pipe[1], loc(F, L), p);
		p->prev_pipe[0] = p->pipe[0];
		p->prev_pipe[1] = p->pipe[1];
	}
	p->is_child = false;
}

int	exec_cmds(t_pipex *p)
{
	int	i;
	int	status;

	get_paths(p);
	p->pids = xmalloc((sizeof(pid_t) * p->n_cmds), loc(F, L), p);
	i = 0;
	while (i < p->n_cmds)
		spawn_child(i++, p);
	xclose(&p->prev_pipe[0], loc(F, L), p);
	xclose(&p->prev_pipe[1], loc(F, L), p);
	xclose(&p->io[0], loc(F, L), p);
	xclose(&p->io[1], loc(F, L), p);
	i = 0;
	while (i < p->n_cmds)
	{
		if (waitpid(p->pids[i++], &status, 0) == -1)
			exit_pipex(loc(F, L), ERR_PERROR, 1, p);
	}
	return (WEXITSTATUS(status));
}
