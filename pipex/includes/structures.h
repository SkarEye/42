/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:32:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/11 19:23:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include <sys/types.h>

typedef struct	s_pipex
{
	char	**cmds;
	int		n_cmds;
	char	**envp;
	char	**paths;

	char	**cmd_args;
	char	*cmd_path;

	int		infile;
	int		outfile;
	bool	use_infile;
	bool	use_outfile;
	char	*in_path;
	char	*out_path;

	char	*stash;
	char	*line;

	pid_t	*pids;
	bool	is_child;
	int		prev_pipe[2];
	int		pipe[2];
}				t_pipex;

#endif