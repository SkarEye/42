/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/26 16:57:24 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"

static bool	all_meals_done(t_sim *sim)
{
	t_uint	i;

	i = 0;
	while (i < sim->n_philos)
	{
		if (sim->philos[i].meals_eaten < sim->meal_goal)
			return (false);
		i++;
	}
	return (true);
}

void	*monitor(void *arg)
{
	t_sim	*sim;
	t_uint	i;

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
