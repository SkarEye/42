/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:06:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/31 12:13:43 by mattcarniel      ###   ########.fr       */
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
#include "../include/monitor.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;

	status = setup_simulation(&sim, argc, argv);

	//printf("Initialized vals : n_philo : %i, time_to_die : %i, time_to_eat : %i, time_to_sleep : %i, meal_goal : %i\n",
	//		sim.n_philos, sim.time_to_die, sim.time_to_eat, sim.time_to_sleep, sim.meal_goal);

	if (status)
		return (cleanup_simulation(&sim, status));
	status = spawn_table(&sim);
	if (status)
		return (cleanup_simulation(&sim, status));
	status = monitor_table(&sim);
	if (status)
		return (cleanup_simulation(&sim, status));
	return (status);
}
