/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/24 14:48:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"

static bool	all_meals_done(t_sim *sim)
{
	uint	i;

	i = 0;
	while (i < sim->n_philos)
	{
		if (sim->philos[i].meals_eaten < sim->meal_goal)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Check if a philosopher has died.
 * @param p philosopher pointer
 * @return true if philosopher has died, false otherwise.
 */
// static bool	check_death(t_philo *p)
// {
// 	ll	time_since_last_meal;

// 	pthread_mutex_lock(&p->last_meal_mutex);
// 	time_since_last_meal = now_ms() - p->last_meal_time;
// 	pthread_mutex_unlock(&p->last_meal_mutex);
// 	return (time_since_last_meal >= p->sim->time_to_die);
// }

#include <stdio.h>

void	*monitor(void *arg)
{
	t_sim	*sim;
	uint	i;

	sim = (t_sim *)arg;
	while (!get_stop(sim))
	{	
		i = 0;
		if (sim->meal_goal > 0 && all_meals_done(sim))
		{
			set_stop(sim, true);
			return (NULL);
		}
		while (i < sim->n_philos)
		{
			if (now_ms() - sim->philos[i].last_meal_time >= sim->time_to_die)
			{
				print_action(&sim->philos[i], DIE);
				set_stop(sim, true);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
