/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:48:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 12:57:53 by mattcarniel      ###   ########.fr       */
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

static int	init_philo(t_philo *p, t_sim *sim, uint id)
{
	int	status;

	p->sim = sim;
	p->id = id;
	p->meals_eaten = 0;
	p->start_time = now_ms();
	p->last_meal_time = p->start_time;
	status = pthread_create(&p->monitor_thread, NULL, &monitor, p);
	if (status)
		return (print_error(loc(F, L), ERR_PERROR, status));
	return (0);
}

int	routine(t_sim *sim, uint id)
{
	t_philo	p;
	int		status;

	status = init_philo(&p, sim, id);
	if (status)
		return (status);
	if (sim->n_philos == 1)
	{
		sem_wait(sim->forks);
		print_action(&p, TAKE_FORK);
		ms_sleep(sim->time_to_die);
		print_action(&p, DIE);
		exit(1);
	}
	while (true)
	{
		eat_spaghetti(&p);
		if (sim->meal_goal > 0 && p.meals_eaten >= sim->meal_goal)
			break ;
		hit_the_sack(&p);
		have_an_existential_crisis(&p);
	}
	exit(0);
	return (0);
}
