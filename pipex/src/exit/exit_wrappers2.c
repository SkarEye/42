/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:12:05 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/07 20:45:33 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "structures.h"
#include "error_utils.h"
#include "exit_utils.h"

#include "exit_wrappers.h"

void	xdup2(int oldfd, int newfd, t_debug dbg, t_pipex *p)
{
	if (dup2(oldfd, newfd) == -1)
	{
		exit_current(dbg, ERR_PERROR, 1, p);
	}
}

void	xpipe(int pipefd[2], t_debug dbg, t_pipex *p)
{
	if (pipe(pipefd) == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
}

pid_t	xfork(t_debug dbg, t_pipex *p)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
	p->is_child = true;
	return (pid);
}

void	xwaitpid(pid_t pid, int *status, int options, t_debug dbg, t_pipex *p)
{
	if (waitpid(pid, status, options) == -1)
		exit_current(dbg, ERR_PERROR, 1, p);
}