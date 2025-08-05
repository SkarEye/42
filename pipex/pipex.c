/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/05 11:01:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "structures.h"
#include "error_utils.h"
#include "exit_utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		exit_pipex(pipex, 0); //what exit_code to give ?
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		exit_pipex(pipex, 0); //what exit_code ?
	
}