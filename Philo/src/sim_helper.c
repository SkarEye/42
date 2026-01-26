/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:28:35 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/24 13:38:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>

#include "../include/structures.h"

/**
 * @brief Get the current time in milliseconds.
 * @return current time.
 */
ll	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((ll)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief Sleep for a given number of milliseconds, as long as simulation is running.
 * @param sim simulation pointer
 * @param ms milliseconds to sleep
 */
void	ms_sleep(t_sim *sim, int ms)
{
	ll	t;

	t = now_ms();
	while (!get_stop(sim))
	{
		if (now_ms() - t >= ms)
			break ;
		usleep(500);
	}
}

/**
 * @brief Get the stop status of the simulation.
 * @param sim simulation pointer
 * @return true if simulation is stopped, false otherwise.
 */
bool	get_stop(t_sim *sim)
{
	bool	stop;

	stop = sim->stop;
	return (stop);
}
/**
 * @brief Set the stop status of the simulation.
 * @param sim simulation pointer
 * @param value value to set
 */
void	set_stop(t_sim *sim, bool value)
{
	sim->stop = value;
}
