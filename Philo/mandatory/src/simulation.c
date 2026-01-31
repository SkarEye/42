/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:55:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 16:44:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/routine.h"
#include "../include/monitor.h"
#include "../include/error.h"

int	setup_simulation(t_sim *sim, int argc, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argc < 5 || argc > 6)
		return (print_error(loc(F, L), ERR_INVALID_ARG_COUNT, EXIT_FAILURE));
	status |= ft_atou_safe(argv[1], &sim->n_philos);
	status |= ft_atou_safe(argv[2], &sim->time_to_die);
	status |= ft_atou_safe(argv[3], &sim->time_to_eat);
	status |= ft_atou_safe(argv[4], &sim->time_to_sleep);
	sim->meal_goal = 0;
	if (argc == 6)
		status |= ft_atou_safe(argv[5], &sim->meal_goal);
	if (status != EXIT_SUCCESS)
		return (print_error(loc(F, L), ERR_INVALID_ARGS, EXIT_FAILURE));
	if (sim->n_philos == 0)
		return (print_error(loc(F, L), ERR_NO_PHILOS, EXIT_FAILURE));
	if (sim->n_philos > MAX_PHILOS)
		return (print_error(loc(F, L), ERR_TOO_MANY_PHILOS, EXIT_FAILURE));
	if ((sim->time_to_die > 0 && sim->time_to_die < MAX_DEATH_TIME)
		&& (sim->time_to_eat > 0 && sim->time_to_eat < MAX_EAT_TIME)
		&& (sim->time_to_sleep > 0 && sim->time_to_sleep < MAX_SLEEP_TIME))
		return (EXIT_SUCCESS);
	return (print_error(loc(F, L), ERR_BAD_VAL, EXIT_FAILURE));
}

void	init_simulation(t_sim *sim)
{
	t_uint	i;

	i = 0;
	sim->threads_created = 0;
	sim->start = false;
	sim->stop = false;
	sim->monitor = false;
	sim->start_time = now_ms();
	pthread_mutex_init(&sim->print_mutex, NULL);
	while (i < sim->n_philos)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].left_fork = i;
		sim->philos[i].right_fork = (i + 1) % sim->n_philos;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].last_meal_time = sim->start_time;
		sim->philos[i].sim = sim;
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
}

int	thread_simulation(t_sim *sim)
{
	int		status;

	status = EXIT_SUCCESS;
	status = pthread_create(&sim->monitor_thread, NULL, &monitor, sim);
	if (status)
		return (print_error(loc(F, L), ERR_PERROR, status));
	else
		sim->monitor = true;
	while (sim->threads_created < sim->n_philos)
	{
		status = pthread_create(&sim->philos[sim->threads_created].thread, NULL,
				&routine, &sim->philos[sim->threads_created]);
		if (status)
			return (print_error(loc(F, L), ERR_PERROR, status));
		sim->threads_created++;
	}
	sim->start = true;
	return (status);
}

void	free_sim(t_sim *sim)
{
	if (sim->philos)
		free(sim->philos);
	if (sim->forks)
		free(sim->forks);
}

void	cleanup_sim(t_sim *sim)
{
	t_uint	i;

	i = 0;
	if (sim->monitor)
		pthread_join(sim->monitor_thread, NULL);
	while (i < sim->threads_created)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < sim->n_philos)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	free_sim(sim);
}
