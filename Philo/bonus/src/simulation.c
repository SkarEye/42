/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:55:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/27 15:10:45 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#include "../include/structures.h"
#include "../include/routine.h"
#include "../include/monitor.h"
#include "../include/error.h"

int	setup_simulation(t_sim *sim, int argc, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;
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
	if ((sim->time_to_die > 0 && sim->time_to_die < MAX_DEATH_TIME)
		&& (sim->time_to_eat > 0 && sim->time_to_eat < MAX_EAT_TIME)
		&& (sim->time_to_sleep > 0 && sim->time_to_sleep < MAX_SLEEP_TIME))
		return (EXIT_SUCCESS);
	sim->forks = sem_open("/forks", O_CREAT, 0644, sim->n_philos);
	return (print_error(loc(F, L), ERR_BAD_VAL, EXIT_FAILURE));
}
