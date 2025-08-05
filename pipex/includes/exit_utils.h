/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:58:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/05 18:02:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_UTILS_H

# define EXIT_UTILS_H

# include "structures.h"

void	free_child(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);
void	exit_child(t_debug dbg, t_error err, int exit_code, t_pipex *pipex);
void	exit_pipex(t_debug dbg, t_error err, int exit_code, t_pipex *pipex);
void	exit_current(t_debug dbg, t_error err, int exit_code, t_pipex *pipex);

#endif