/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:59:20 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/13 17:31:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"

#include "exit_utils.h"

#include <stdio.h>

void	free_child(t_pipex *pipex)
{
	if (!pipex)
		return ;
	ft_free_strtab(pipex->cmd_args);
	pipex->cmd_args = NULL;
	if (pipex->cmd_path)
		free(pipex->cmd_path);
	pipex->cmd_path = NULL;
	if (pipex->pipe[0] > 2)
		close(pipex->pipe[0]);
	if (pipex->pipe[1] > 2)
		close(pipex->pipe[1]);
	if (pipex->infile > 2)
		close(pipex->infile);
	if (pipex->outfile > 2)
		close(pipex->outfile);
}

void	free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmds)
		ft_free_strtab(pipex->cmds);
	pipex->n_cmds = 0;
	if (pipex->pids)
		free(pipex->pids);
	if (pipex->stash)
		free(pipex->stash);
	if (pipex->line)
		free(pipex->line);
	ft_free_strtab(pipex->paths);
	ft_free_strtab(pipex->cmd_args);
	if (pipex->cmd_path)
		free(pipex->cmd_path);
	if (pipex->pipe[0] > 2)
		close(pipex->pipe[0]);
	if (pipex->pipe[1] > 2)
		close(pipex->pipe[1]);
	if (pipex->infile > 2)
		close(pipex->infile);
	if (pipex->outfile > 2)
		close(pipex->outfile);
	ft_bzero(pipex, sizeof(t_pipex));
	free(pipex);
}

void	exit_child(t_debug dbg, t_error err, int exit_code, t_pipex *pipex)
{
	print_error(dbg, err, false);
	if (!pipex)
		exit(exit_code);
	if (!pipex->is_child)
	{
		print_error(loc(F, L), ERR_CHILD_EXIT, false);
		return ;
	}
	pipex->is_child = false;
	free_pipex(pipex);
	if (exit_code < 0 || exit_code > 255)
		exit_code = 1;
	exit(exit_code);
}

void	exit_pipex(t_debug dbg, t_error err, int exit_code, t_pipex *pipex)
{
	print_error(dbg, err, false);
	if (!pipex)
		exit(exit_code);
	if (pipex->is_child)
	{
		print_error(loc(F, L), ERR_PARENT_EXIT, false);
		return ;
	}
	free_pipex(pipex);
	if (exit_code < 0 || exit_code > 255)
		exit_code = 1;
	exit(exit_code);
}

void	exit_current(t_debug dbg, t_error err, int exit_code, t_pipex *pipex)
{
	if (!pipex)
		exit(exit_code);
	if (pipex->is_child)
		exit_child(dbg, err, exit_code, pipex);
	else
		exit_pipex(dbg, err, exit_code, pipex);
}
