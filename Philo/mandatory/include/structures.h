/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 14:16:04 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>

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

typedef unsigned int	t_uint;
typedef long long		t_ll;
typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_sim	t_sim;

typedef struct s_philo
{
	t_uint			id;
	int				left_fork;
	int				right_fork;
	_Atomic(t_uint)	meals_eaten;
	_Atomic(t_ll)	last_meal_time;
	t_thread		thread;
	t_sim			*sim;
}	t_philo;

struct s_sim
{
	t_uint			n_philos;
	t_uint			time_to_die;
	t_uint			time_to_eat;
	t_uint			time_to_sleep;
	t_uint			meal_goal;
	t_uint			meal_goal_reached;
	t_uint			threads_created;
	_Atomic(bool)	stop;
	bool			monitor;
	t_mutex			*forks;
	t_mutex			print_mutex;
	t_thread		monitor_thread;
	t_ll			start_time;
	struct s_philo	*philos;
};

t_ll	now_ms(void);
bool	get_stop(t_sim *sim);
void	set_stop(t_sim *sim, bool b);
void	ms_sleep(t_sim *sim, int ms);

#endif