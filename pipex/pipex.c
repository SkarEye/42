/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/10 16:48:39 by macarnie         ###   ########.fr       */
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

#define HERE_DOC	"here_doc"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = xcalloc(sizeof(t_pipex), ERR_LOC, pipex);
	if (argc < 5)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	if (!envp || !*envp)
		exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
	if (ft_strncmp(argv[1], HERE_DOC, 9) == 0)
	{
		if (argc < 6)
			exit_pipex(ERR_LOC, ERR_BAD_ARGS, 1, pipex);
		get_here_doc(argv[2], pipex); // set limiter (first arg)
	}
	else
		pipex->infile = xopen(argv[1], O_RDONLY, 0, ERR_LOC, pipex);
	pipex->out_path = argv[argc - 1];
	pipex->n_cmds = argc - 3;
	pipex->cmds = ft_strtabndup(&argv[2], pipex->n_cmds);
	if (!pipex->cmds)
		exit_pipex(ERR_LOC, ERR_PERROR, 1, pipex);
	pipex->envp = envp;
	exec_cmds(pipex);
	free_pipex(pipex);
	return (0);
}
