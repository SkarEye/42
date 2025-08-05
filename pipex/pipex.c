/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:45:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/01 14:48:13 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "error_utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (1)
}