/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:55:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/31 12:20:34 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#include "../include/structures.h"
#include "../include/error.h"


int	cleanup_simulation(t_sim *sim, int status)
{
	if (sim->forks && sim->forks != SEM_FAILED)
		sem_close(sim->forks);
	if (sim->print_lock && sim->print_lock != SEM_FAILED)
		sem_close(sim->print_lock);
	if (sim->meals_sem && sim->meals_sem != SEM_FAILED)
		sem_close(sim->meals_sem);
	if (sim->death_sem && sim->death_sem != SEM_FAILED)
		sem_close(sim->death_sem);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/meals_sem");
	sem_unlink("/death_sem");
	if (sim->pids)
		free(sim->pids);
	sim->pids = NULL;
	return (status);
}

static int	setup_mallocs(t_sim *sim)
{
	sim->pids = malloc(sizeof(pid_t) * sim->n_philos);
	if (!sim->pids)
		return (print_error(loc(F, L), ERR_PERROR, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

static int	setup_semaphores(t_sim *sim)
{
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/meals_sem");
	sem_unlink("/death_sem");
	sim->forks = sem_open("/forks", O_CREAT, 0644, sim->n_philos);
	if (sim->forks == SEM_FAILED)
		return (print_error(loc(F, L), ERR_PERROR, EXIT_FAILURE));
	sim->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	if (sim->print_lock == SEM_FAILED)
		return (print_error(loc(F, L), ERR_PERROR, EXIT_FAILURE));
	sim->meals_sem = sem_open("/meals_sem", O_CREAT, 0644, 0);
	if (sim->meals_sem == SEM_FAILED)
		return (print_error(loc(F, L), ERR_PERROR, EXIT_FAILURE));
	sim->death_sem = sem_open("/death_sem", O_CREAT, 0644, 0);
	if (sim->death_sem == SEM_FAILED)
		return (print_error(loc(F, L), ERR_PERROR, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int	setup_simulation(t_sim *sim, int argc, char **argv)
{
	int	status;

	status = 0;
	memset(sim, 0, sizeof(t_sim));
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
	if (!(sim->time_to_die > 0 && sim->time_to_die < MAX_DEATH_TIME)
		|| !(sim->time_to_eat > 0 && sim->time_to_eat < MAX_EAT_TIME)
		|| !(sim->time_to_sleep > 0 && sim->time_to_sleep < MAX_SLEEP_TIME))
		return (print_error(loc(F, L), ERR_BAD_VAL, EXIT_FAILURE));
	status = setup_mallocs(sim) | setup_semaphores(sim);
	return (status);
}
