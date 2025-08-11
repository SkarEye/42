/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:15:36 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/11 14:49:24 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_WRAPPERS_H
# define EXIT_WRAPPERS_H

# include <stddef.h>
# include <sys/types.h>

# include "structures.h"

void	*xmalloc(size_t size, t_debug dbg, t_pipex *p);
void	*xcalloc(size_t size, t_debug dbg, t_pipex *p);
void	*xrealloc(void *ptr, size_t old, size_t new, t_debug dbg, t_pipex *p);
int		xopen(const char *path, int flg, mode_t mode, t_debug dbg, t_pipex *p);
void	xclose(int *fd, t_debug dbg, t_pipex *p);

void	xdup2(int oldfd, int newfd, t_debug dbg, t_pipex *p);
void	xpipe(int pipefd[2], t_debug dbg, t_pipex *p);
pid_t	xfork(t_debug dbg, t_pipex *p);
void	xwaitpid(pid_t pid, int *status, int options, t_debug dbg, t_pipex *p);

#endif