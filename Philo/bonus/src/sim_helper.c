/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:28:35 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 12:58:06 by mattcarniel      ###   ########.fr       */
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
t_ll	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((t_ll)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief Sleep for a given number of milliseconds.
 * @param ms Number of milliseconds to sleep.
 */
void	ms_sleep(int ms)
{
	t_ll	start_time;

	start_time = now_ms();
	while (now_ms() - start_time < ms)
		usleep(100);
}
