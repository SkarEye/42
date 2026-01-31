/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:09:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/31 13:15:37 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/structures.h"
#include "../include/routine.h"

void	kill_table(t_sim *sim)
{
	t_uint	i;

	i = 0;
	while (i < sim->n_philos)
		kill(sim->pids[i++], SIGKILL);
	i = 0;
	while (i < sim->n_philos)
		waitpid(sim->pids[i++], NULL, 0);
}

static int	spawn_philo(t_uint id, t_sim *sim)
{
	sim->pids[id] = fork();
	if (sim->pids[id] < 0)
	{
		while (id-- > 0)
			kill(sim->pids[id], SIGTERM);
		waitpid(-1, NULL, 0);
		return (EXIT_FAILURE);
	}
	else if (sim->pids[id] == 0)
		routine(sim, id);
	return (0);
}

int	spawn_table(t_sim *sim)
{
	t_uint	i;
	int		status;

	i = 0;
	sim->start_time = now_ms();
	while (i < sim->n_philos)
	{
		status = spawn_philo(i++, sim);
		if (status)
			return (status);
	}
	return (0);
}
