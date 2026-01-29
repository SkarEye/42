/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/27 15:07:53 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H


# include <stdbool.h>
# include <sys/types.h>
# include <semaphore.h>

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

typedef struct s_sim	t_sim;

typedef struct s_philo
{
	t_uint			id;
	t_state			state;
	t_thread		thread;
	t_sim			*sim;
}	t_philo;

struct s_sim
{
	t_ll			start_time;
	t_ll			last_meal_time;

	t_uint			n_philos;
	t_uint			time_to_die;
	t_uint			time_to_eat;
	t_uint			time_to_sleep;

	t_uint			meal_goal;
	t_uint			meals_eaten;

	t_state			state;

	sem_t			*forks;

	pid_t			*pids;

	bool			monitor;
	struct s_philo	*philos;
};

t_ll	now_ms(void);
bool	get_stop(t_sim *sim);
void	set_stop(t_sim *sim, bool b);
void	ms_sleep(t_sim *sim, int ms);

#endif