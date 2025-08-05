/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/05 18:23:48 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "args.h"
#include "utils.h"
#include "structures.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

#include "exec_cmd.h"

#define PATH	"PATH="

static void	get_paths(t_pipex *pipex)
{
	char	*paths;
	size_t  i;

	if (!pipex->envp)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 0, pipex);
	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], PATH, 5) == 0)
		{
			paths = pipex->envp[i] + 5;
			pipex->paths = ft_split(paths, ':');
			if (!pipex->paths)
				exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
			return ;
		}
		i++;
	}
	print_error(ERR_LOC, ERR_NO_PATH, SILENT); //Is this fatal ?
}

static void	get_cmd_path(int n, t_pipex *pipex)
{
	char	*cmd_path;
	size_t	i;

	if (!pipex->cmds[n] || !pipex->paths || !(*pipex->paths))
		exit_child(ERR_LOC, ERR_BAD_ARGS, 0, pipex);
	
	i = 0;
	while (pipex->paths[i])
	{
		pipex->cmd_path = ft_join(pipex->paths[i], pipex->cmds[n], '/');
		if (!pipex->cmd_path)
			exit_child(ERR_LOC, ERR_PERROR, 1, pipex);
		if (access(cmd_path, X_OK) == 0)
			return ;
		free(pipex->cmd_path);
		i++;
	}
	exit_child(ERR_LOC, ERR_NO_CMD, 127, pipex);
}

static void	exec_cmd(int n, t_pipex *pipex)
{
	pipex->cmd_args = split_args(pipex->cmds[n]);
	if (!pipex->cmd_args || !pipex->cmd_args[0])
		exit_child(ERR_LOC, ERR_BAD_PARSE, 2, pipex);
	get_cmd_path(pipex->cmd_args[0], pipex->paths);
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->envp) == -1)
		exit_child(ERR_LOC, ERR_BAD_EXECVE, 126, pipex);
}

static void	spawn_child_process(int n, t_pipex *pipex)
{
	xpipe(pipex->pipe, ERR_LOC, pipex);
	pipex->pids[n] = xfork(ERR_LOC, pipex);
	if (pipex->pids[n] == 0)
	{
		if (n == 0)
			xdup2(pipex->infile, STDIN_FILENO, ERR_LOC, pipex);
		else if (!pipex->cmds[n + 1])
			xdup2(pipex->outfile, STDOUT_FILENO, ERR_LOC, pipex);
		else
			xdup2(pipex->prev_pipe[0], STDIN_FILENO, ERR_LOC, pipex);
		xdup2(pipex->pipe[1], STDOUT_FILENO, ERR_LOC, pipex);
		xclose(pipex->pipe[0], ERR_LOC, pipex);
		xclose(pipex->pipe[1], ERR_LOC, pipex);
		if (n)
			xclose(pipex->prev_pipe[0], ERR_LOC, pipex);
		exec_cmd(n, pipex);
	}
	else
	{
		if (n)
			xclose(pipex->prev_pipe[0], ERR_LOC, pipex);
		xclose(pipex->pipe[1], ERR_LOC, pipex);
		pipex->prev_pipe[0] = pipex->pipe[0];
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
		spawn_child_process(i++, pipex);
	xclose(pipex->infile, ERR_LOC, pipex);
	xclose(pipex->outfile, ERR_LOC, pipex);
	i = 0;
	while (i < pipex->n_cmds)
		xwaitpid(pipex->pids[i++], &status, 0, ERR_LOC, pipex);
}
