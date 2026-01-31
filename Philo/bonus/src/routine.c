/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:48:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/31 13:16:02 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"
#include "../include/monitor.h"
#include "../include/error.h"

static void	eat_spaghetti(t_philo *p)
{
	sem_wait(p->sim->forks);
	print_action(p, TAKE_FORK);
	sem_wait(p->sim->forks);
	print_action(p, TAKE_FORK);
	p->last_meal_time = now_ms();
	print_action(p, EAT);
	ms_sleep(p->sim->time_to_eat);
	p->meals_eaten++;
	if (p->sim->meal_goal > 0 && p->meals_eaten == p->sim->meal_goal)
		sem_post(p->sim->meals_sem);
	sem_post(p->sim->forks);
	sem_post(p->sim->forks);
}

static void	hit_the_sack(t_philo *p)
{
	print_action(p, SLEEP);
	ms_sleep(p->sim->time_to_sleep);
}

static void	have_an_existential_crisis(t_philo *p)
{
	print_action(p, THINK);
}

static t_philo	*init_philo(t_sim *sim, uint id)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	if (!p)
	{
		print_error(loc(F, L), ERR_PERROR, ENOMEM);
		return (NULL);
	}
	p->sim = sim;
	p->id = id;
	p->meals_eaten = 0;
	p->last_meal_time = p->sim->start_time;
	if (pthread_create(&p->monitor_thread, NULL, &monitor_philo, p))
	{
		free(p);
		print_error(loc(F, L), ERR_PERROR, ENOMEM);
		return (NULL);
	}
	return (p);
}

int	routine(t_sim *sim, uint id)
{
	t_philo	*p;

	p = init_philo(sim, id);
	if (!p)
		exit(errno);
	if (sim->n_philos == 1)
	{
		sem_wait(sim->forks);
		print_action(p, TAKE_FORK);
		ms_sleep(sim->time_to_die);
		return (0);
	}
	while (true)
	{
		eat_spaghetti(p);
		hit_the_sack(p);
		have_an_existential_crisis(p);
	}
	pthread_join(p->monitor_thread, NULL);
	free(p);
	exit(0);
}
