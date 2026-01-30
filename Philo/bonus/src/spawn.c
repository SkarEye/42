/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:09:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 13:00:37 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/structures.h"
#include "../include/routine.h"

static void	kill_table(t_sim *sim, pid_t dead_pid)
{
	t_uint	i;

	i = 0;
	while (i < sim->n_philos)
	{
		if (sim->pids[i] > 0 && sim->pids[i] != dead_pid)
			kill(sim->pids[i], SIGTERM);
		i++;
	}
	i = 0;
	while (i < sim->n_philos)
		waitpid(sim->pids[i++], NULL, 0);
}

static void	spawn_philo(t_uint id, t_sim *sim)
{
	int	status;

	sim->pids[id] = fork();
	if (sim->pids[id] < 0)
	{
		while (id-- > 0)
			kill(sim->pids[id], SIGTERM);
		exit(1);
	}
	else if (sim->pids[id] == 0)
	{
		status = routine(sim, id);
		exit(status);
	}
}

static void	supervise(t_sim *sim)
{
	pid_t	pid;
	int		status;
	t_uint	finished;

	finished = 0;
	while (finished < sim->n_philos)
	{
		pid = waitpid(-1, &status, 0);
		if (pid < 0)
			break ;
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
			{
				kill_table(sim, pid);
				return ;
			}
			else
				finished++;
		}
	}
}

int	spawn_table(t_sim *sim)
{
	t_uint	i;

	i = 0;
	while (i < sim->n_philos)
		spawn_philo(i++, sim);
	supervise(sim);
	return (0);
}
