/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:32:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 13:43:29 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_pipex
{
	char	**cmds;
	char	**envp;
	char	**paths;

	char	**cmd_args;
	char	*cmd_path;
}				t_pipex;

#endif