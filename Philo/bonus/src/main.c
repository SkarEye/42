/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:06:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/29 16:37:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#include "../include/structures.h"
#include "../include/simulation.h"
#include "../include/spawn.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;

	status = setup_simulation(&sim, argc, argv);
	if (status)
	{
		cleanup_mallocs(&sim);
		cleanup_semaphores(&sim);
		return (status);
	}
	status = spawn_table(&sim);
	cleanup_semaphores(&sim);
	return (status);
}
