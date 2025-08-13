/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:26:45 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/13 17:31:53 by macarnie         ###   ########.fr       */
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

static void	get_custom_path(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	if (pipex->cmd_args[0][i] == '.' || pipex->cmd_args[0][i] == '/')
	{
		while (pipex->cmd_args[0][i] == '.')
			i++;
		if (pipex->cmd_args[0][i] != '/')
			exit_child(loc(F, L), ERR_NO_CMD, 127, pipex);
		if (access(pipex->cmd_args[0], X_OK) == 0)
		{
			pipex->cmd_path = ft_strdup(pipex->cmd_args[0]);
			if (!pipex->cmd_path)
				exit_child(loc(F, L), ERR_PERROR, 1, pipex);
			return ;
		}
		exit_child(loc(F, L), ERR_NO_CMD, 127, pipex);
	}
}

static void	find_path(t_pipex *pipex)
{
	size_t	i;

	if (!pipex->paths || !(*pipex->paths))
		exit_child(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	i = 0;
	while (pipex->paths[i])
	{
		pipex->cmd_path = ft_join(pipex->paths[i], pipex->cmd_args[0], '/');
		if (!pipex->cmd_path)
			exit_child(loc(F, L), ERR_PERROR, 1, pipex);
		if (access(pipex->cmd_path, X_OK) == 0)
			return ;
		if (pipex->cmd_path)
			free(pipex->cmd_path);
		pipex->cmd_path = NULL;
		i++;
	}
	exit_child(loc(F, L), ERR_NO_CMD, 127, pipex);
}

void	get_paths(t_pipex *pipex)
{
	char	*paths;
	size_t	i;

	if (!pipex->envp)
		exit_pipex(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], PATH, 5) == 0)
		{
			paths = pipex->envp[i] + 5;
			pipex->paths = ft_split(paths, ':');
			if (!pipex->paths)
				exit_pipex(loc(F, L), ERR_PERROR, 1, pipex);
			return ;
		}
		i++;
	}
	print_error(loc(F, L), ERR_NO_PATH, false);
}

void	get_cmd_path(t_pipex *pipex)
{
	if (!pipex->cmd_args[0])
		exit_child(loc(F, L), ERR_BAD_ARGS, 1, pipex);
	if (*pipex->cmd_args[0] == '.' || *pipex->cmd_args[0] == '/')
		get_custom_path(pipex);
	else
		find_path(pipex);
}
