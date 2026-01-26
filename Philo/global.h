/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:45:04 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:41:36 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct s_debug
{
	const char	*file;
	int			line;

	char		reserved[4];
}				t_debug;

# define F	__FILE__
# define L	__LINE__

typedef enum	e_error
{
	ERR_NONE,
	ERR_INVALID_ARG_COUNT,
	ERR_INVALID_ARGS,
	ERR_NO_PHILOS,
	ERR_TOO_MANY_PHILOS,
	ERR_BAD_VAL,
	ERR_PERROR,
	ERR_UNKNOWN,
	ERR_COUNT
}
	t_error;

t_debug	loc(const char *file, int line);
int		print_error(t_debug dbg, t_error err, int int_code);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:09:27 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 21:15:02 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

void		*monitor(void *arg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:26:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 17:42:17 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ACTION_H
# define PRINT_ACTION_H

# include "structures.h"

typedef enum e_action
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
	UNKNOWN,
	COUNT
}	t_action;

void	print_action(t_philo *philo, t_action action);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:14:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 18:51:14 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

void	*routine(void *arg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:47:46 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:04:29 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "structures.h"

int		setup_simulation(t_sim *sim, int argc, char **argv);
void	init_simulation(t_sim *sim);
int		thread_simulation(t_sim *sim);
void	free_sim(t_sim *sim);
void	cleanup_sim(t_sim *sim);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:11:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:35:00 by mattcarniel      ###   ########.fr       */
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
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	_Atomic(ll)		last_meal_time;
	t_state			state;
	mutex			last_meal_mutex;
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