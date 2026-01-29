/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:06:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/27 15:06:58 by macarnie         ###   ########.fr       */
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
#include "../include/error.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;
	t_uint	i;

	status = setup_simulation(&sim, argc, argv);
	if (status != EXIT_SUCCESS)
		return (status);
	i = 0;
	while (i < sim.n_philos)
		spawn_child(i++, sim);




}
{
	sim.philos = malloc(sizeof(t_philo) * sim.n_philos);
	if (!sim.philos)
		return (print_error(loc(F, L), ERR_PERROR, ENOMEM));
	sim.forks = malloc(sizeof(pthread_mutex_t) * sim.n_philos);
	if (!sim.forks)
		return (free_sim(&sim), print_error(loc(F, L), ERR_PERROR, ENOMEM));
	init_simulation(&sim);
	status = thread_simulation(&sim);
	cleanup_sim(&sim);
	return (status);
}
