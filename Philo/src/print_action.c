/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:27:20 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 16:06:41 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include <unistd.h>

#include "../include/print_action.h"
#include "../include/structures.h"

#ifdef FUNKY
static const char *get_action(t_action action)
{
	const char *actions[] = {
		"has picked up a spork",
		"is slurping spaghetti",
		"is playing baseball with the stars",
		"is trying to understand how one can become sentient",
		"starved and withered away ...",
		"is going rogue !"
	};
	if (action < 0 || action >= COUNT)
		return (actions[UNKNOWN]);
	return (actions[action]);

}
#else
static const char *get_action(t_action action)
{
	const char *actions[] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
		"is going rogue !"
	};
	if (action < 0 || action >= COUNT)
		return (actions[UNKNOWN]);
	return (actions[action]);

}
#endif

void	print_action(t_philo *p, t_action action)
{
	char		buf[64];
	size_t		i;

	pthread_mutex_lock(&p->sim->print_mutex); //necessary ?
	if (!p->sim->stop || action == DIE)
	{
		i = ft_sutoa(buf, now_ms() - p->sim->start_time);
		buf[i++] = ' ';
		i += ft_sitoa(&buf[i], p->id);
		buf[i++] = ' ';
		i += ft_strlcpy(&buf[i], get_action(action), sizeof(buf) - i);
		buf[i++] = '\n';
		buf[i] = '\0';
		write(1, buf, i);
	}
	pthread_mutex_unlock(&p->sim->print_mutex);
}
