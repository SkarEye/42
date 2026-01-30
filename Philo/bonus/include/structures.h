/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 14:16:35 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include <sys/types.h>
# include <pthread.h>
# include <semaphore.h>

# include "../../utils/include/utils.h"

# ifndef MAX_PHILOS
#  define MAX_PHILOS 200
# endif

# ifndef MAX_DEATH_TIME
#  define MAX_DEATH_TIME 10000
# endif

# ifndef MAX_EAT_TIME
#  define MAX_EAT_TIME 5000
# endif

# ifndef MAX_SLEEP_TIME
#  define MAX_SLEEP_TIME 5000
# endif

typedef unsigned int		t_uint;
typedef long long			t_ll;

typedef struct s_sim
{
	t_uint			n_philos;
	t_uint			time_to_die;
	t_uint			time_to_eat;
	t_uint			time_to_sleep;
	t_uint			meal_goal;

	sem_t			*forks;
	sem_t			*print_lock;
	sem_t			*stop_lock;

	pid_t			*pids;
}	t_sim;

typedef struct s_philo
{
	t_sim			*sim;

	t_ll			start_time;
	_Atomic(t_ll)	last_meal_time;
	t_uint			meals_eaten;

	t_uint			id;

	pthread_t		monitor_thread;
}	t_philo;

t_ll	now_ms(void);
void	ms_sleep(int ms);

#endif