/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:59:20 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:06:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

#include "exit_utils.h"

void	free_pipex(t_pipex *pipex)
{
	free_split(pipex->paths);
	free_split(pipex->cmd_args);
	if (pipex->cmd_path)
		free(pipex->cmd_path);
}

void	exit_pipex(t_pipex *pipex, int  exit_code)
{
	free_pipex(pipex);
	exit(exit_code); //if statement for exit_code val ?
}
