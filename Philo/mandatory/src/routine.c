/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:48:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 16:45:48 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"

static void	eat_spaghetti(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->sim->forks[p->right_fork]);
		print_action(p, TAKE_FORK);
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
		pthread_mutex_lock(&p->sim->forks[p->right_fork]);
		print_action(p, TAKE_FORK);
	}
	p->last_meal_time = now_ms();
	print_action(p, EAT);
	ms_sleep(p->sim, p->sim->time_to_eat);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->sim->forks[p->right_fork]);
	pthread_mutex_unlock(&p->sim->forks[p->left_fork]);
}

static void	hit_the_sack(t_philo *p)
{
	print_action(p, SLEEP);
	ms_sleep(p->sim, p->sim->time_to_sleep);
}

static void	have_an_existential_crisis(t_philo *p)
{
	print_action(p, THINK);
	if (p->sim->n_philos % 2 == 1)
		ms_sleep(p->sim, p->sim->time_to_eat);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->sim->start)
		usleep(100);
	if (p->sim->n_philos == 1)
	{
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
		ms_sleep(p->sim, p->sim->time_to_die);
		pthread_mutex_unlock(&p->sim->forks[p->left_fork]);
		return (NULL);
	}
	if (p->id % 2 == 1)
		ms_sleep(p->sim, 1);
	if (p->id == p->sim->n_philos)
		ms_sleep(p->sim, p->sim->time_to_eat * 2 - 10);
	while (!get_stop(p->sim))
	{
		eat_spaghetti(p);
		hit_the_sack(p);
		have_an_existential_crisis(p);
	}
	return (NULL);
}
