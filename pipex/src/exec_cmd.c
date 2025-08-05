/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:59:57 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "args.h"
#include "utils.h"
#include "structures.h"
#include "error_utils.h"
#include "exit_utils.h"

#include "exec_cmd.h"

#define PATH	"PATH="

static char	*make_cmd_path(const char *path, const char *cmd)
{
	if (!path || !cmd)
		return (NULL);
	return (ft_join(path, cmd, '/'));
}

static char	*get_cmd_path(const char *cmd, char **paths)
{
	char	*cmd_path;
	size_t	i;

	if (!cmd || !paths || !(*paths))
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = make_cmd_path(paths[i], cmd);
		if (!cmd_path)
			return (free_split(paths), NULL); // No need for 
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(paths);
			return (cmd_path); // GOOD RETURN HERE
		}
		free(cmd_path);
		i++;
	}
	return (free_split(paths), NULL);
}

char	**get_paths(char **envp)
{
	size_t  i;
	char    *paths;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], PATH, 5) == 0) //change to libft ft_strncmp
		{
			paths = envp[i] + 5;
			return (ft_split(paths, ':'));
		}
		i++;
	}
	return (print_error(ERR_LOC, ERR_BAD_FIND, false), NULL);
}

void	exec_cmd(char *cmd_str, t_pipex *pipex)
{
	pipex->cmd_args = split_args(cmd_str);
	if (!pipex->cmd_args || !pipex->cmd_args[0])
	{
		print_error(ERR_LOC, ERR_BAD_PARSE, false);
		exit_pipex(pipex, 2);
	}
	pipex->cmd_path = get_cmd_path(pipex->cmd_args[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		print_error(ERR_LOC, ERR_NO_CMD, false);
		exit_pipex(pipex, 127);
	}
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->envp) == -1)
	{
		print_error(ERR_LOC, ERR_BAD_EXECVE, false);
		exit_pipex(pipex, 126);
	}
	free_split(pipex->cmd_args);
	free(pipex->cmd_path);
}
