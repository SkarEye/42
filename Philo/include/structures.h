/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/24 14:48:15 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>

# include "utils.h"

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

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_state;

typedef struct s_sim t_sim;

typedef struct s_philo
{
	uint			id;
	int				left_fork;
	int				right_fork;
	_Atomic(uint)	meals_eaten;
	_Atomic(ll)		last_meal_time;
	t_state			state;
	thread			thread;
	t_sim			*sim;
}	t_philo;

struct s_sim
{
	uint			n_philos;
	uint			time_to_die;
	uint			time_to_eat;
	uint			time_to_sleep;
	uint			meal_goal;
	uint			meal_goal_reached; // can i do this ?
	uint			threads_created;
	_Atomic(bool)	stop;
	bool			monitor;
	mutex			*forks;
	mutex			print_mutex;
	thread			monitor_thread;
	ll				start_time;
	struct s_philo	*philos;
};

ll		now_ms(void);
bool	get_stop(t_sim *sim);
void	set_stop(t_sim *sim, bool b);
void	ms_sleep(t_sim *sim, int ms);

#endif