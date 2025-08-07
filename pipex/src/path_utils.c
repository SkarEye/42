/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:26:45 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/07 16:36:32 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "error_utils.h"
#include "exit_utils.h"

#include "path_utils.h"

#define PATH	"PATH="

static void	get_custom_path(int n, t_pipex *pipex)
{
	size_t	i;

	i= 0;
	if (pipex->cmds[n][i] == '.' || pipex->cmds[n][i] == '/')
	{
		while (pipex->cmds[n][i] == '.')
			i++;
		if (pipex->cmds[n][i] != '/')
			exit_child(ERR_LOC, ERR_NO_CMD, 127, pipex);
		if (access(pipex->cmds[n], X_OK) == 0)
		{
			pipex->cmd_path = ft_strdup(pipex->cmds[n]);
			if (!pipex->cmd_path)
				exit_child(ERR_LOC, ERR_PERROR, 1, pipex);
			return ;
		}
		exit_child(ERR_LOC, ERR_NO_CMD, 127, pipex);
	}
}

static void	find_path(int n, t_pipex *pipex)
{
	size_t	i;

	if (!pipex->paths || !(*pipex->paths))
		exit_child(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	i= 0;
	while (pipex->paths[i])
	{
		pipex->cmd_path = ft_join(pipex->paths[i], pipex->cmds[n], '/');
		if (!pipex->cmd_path)
			exit_child(ERR_LOC, ERR_PERROR, 1, pipex);
		if (access(pipex->cmd_path, X_OK) == 0)
			return ;
		free(pipex->cmd_path);
		i++;
	}
	exit_child(ERR_LOC, ERR_NO_CMD, 127, pipex);
}

void	get_paths(t_pipex *pipex)
{
	char	*paths;
	size_t  i;

	if (!pipex->envp)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
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
	print_error(ERR_LOC, ERR_NO_PATH, SILENT);
}

void	get_cmd_path(int n, t_pipex *pipex)
{
	if (!pipex->cmds[n])
		exit_child(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	if (*pipex->cmds[n] == '.' || *pipex->cmds[n] == '/')
		get_custom_path(n, pipex);
	else
		find_path(n, pipex);
}
