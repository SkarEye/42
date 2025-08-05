/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:58:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:07:59 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_UTILS_H

# define EXIT_UTILS_H

# include "structures.h"

void    free_pipex(t_pipex *pipex);
void	exit_pipex(t_pipex *pipex, int exit_code);

#endif