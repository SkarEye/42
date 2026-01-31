/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:18:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/31 13:09:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/structures.h"
#include "../include/spawn.h"
#include "../include/print_action.h"
#include "../include/error.h"

static bool	check_death(t_philo *p)
{
	if (now_ms() - p->last_meal_time >= p->sim->time_to_die)
		return (true);
	return (false);
}

void	*monitor_philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (true)
	{
		if (check_death(p))
		{
				print_action(p, DIE);
				sem_post(p->sim->death_sem);
				while (true)
					usleep(1000);
		}
		usleep(1000);
	}
	return (NULL);
}

static void	*monitor_meals(void *arg)
{
	t_sim	*sim;
	t_uint	finished;

	sim = (t_sim *)arg;
	finished = 0;
	while (finished < sim->n_philos)
	{
		sem_wait(sim->meals_sem);
		finished++;
	}
	sem_post(sim->death_sem);
	return (NULL);
}

int	monitor_table(t_sim *sim)
{
	pthread_t	meals_thread;
	int			status;

	status = 0;
	if (sim->meal_goal > 0)
	{
		status = pthread_create(&meals_thread, NULL, &monitor_meals, sim);
		if (status)
			return (print_error(loc(F, L), ERR_PERROR, status));
	}
	sem_wait(sim->death_sem);
	kill_table(sim);
	return (status);
}
