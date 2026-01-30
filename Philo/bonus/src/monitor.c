/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:18:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 12:56:57 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "../include/structures.h"
#include "../include/print_action.h"

void	*monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		if (now_ms() - p->last_meal_time >= p->sim->time_to_die)
			break ;
		usleep(1000);
	}
	print_action(p, DIE);
	exit(1);
	return (NULL);
}
