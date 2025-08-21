/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:32:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/21 19:44:36 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include <sys/types.h>

typedef struct s_pipex
{
	char	**cmds;
	char	**envp;
	char	**paths;

	char	**cmd_args;
	char	*cmd_path;

	char	*outpath;
	
	char	*lmt;
	char	*stash;
	char	*line;
	
	pid_t	*pids;
	
	int		io[2];
	int		prev_pipe[2];
	int		pipe[2];
	int		n_cmds;
	bool	is_here_doc;
	bool	is_child;
	
	char	reserved[2];
}				t_pipex;

#endif