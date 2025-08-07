/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/07 17:22:27 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h> //for NULL ?

#include "structures.h"
#include "utils.h"
#include "exec_utils.h"
#include "error_utils.h"
#include "exit_utils.h"
#include "exit_wrappers.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (argc < 5)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	if (!envp || !*envp)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex); //other exit_code ?
	pipex = xmalloc(sizeof(t_pipex), ERR_LOC, pipex);
	pipex->infile = xopen(argv[1], O_RDONLY, 0, ERR_LOC, pipex);
	pipex->outfile = xopen(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644, ERR_LOC, pipex);
	pipex->n_cmds = argc - 3;
	pipex->cmds = ft_strtabndup(&argv[2], pipex->n_cmds);
	if (!pipex->cmds)
		exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
	pipex->envp = envp;
	exec_cmds(pipex);
	return (0);
}
