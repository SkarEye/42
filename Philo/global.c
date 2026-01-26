/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:20:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:40:49 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "../include/error.h"
#include "../include/utils.h"

#define NO_FILE_CONTEXT 	"no file context"
#define THREE_DOT			"..."

#define MSG_LIMIT			128
#define FILE_LIMIT			16
#define INFO_LIMIT			96

static const char	*get_error_info(t_error err)
{
	static const char	*info[] = {
		[ERR_NONE] = ": Success",
		[ERR_INVALID_ARG_COUNT] = " : Invalid number of arguments",
		[ERR_INVALID_ARGS] = " : Invalid arguments given",
		[ERR_NO_PHILOS] = " : Simulation must have at least ONE philosopher",
		[ERR_TOO_MANY_PHILOS] = " : Simulation has too many philosophers to handle",
		[ERR_BAD_VAL] = " : One or more of the given values are outside of their scope",
		[ERR_PERROR] = " : System error",
		[ERR_UNKNOWN] = " : Unknown error"
		};

	if (err < 0 || err >= ERR_COUNT)
		return (info[ERR_UNKNOWN]);
	return (info[err]);
}

static size_t	get_syscontext(char *buf, t_debug dbg)
{
	size_t	i;

	i = ft_strlcpy(buf, dbg.file, FILE_LIMIT + 1);
	if (i > FILE_LIMIT)
		i = FILE_LIMIT + ft_strlcpy(&buf[FILE_LIMIT], THREE_DOT, 4);
	if (dbg.line > 0)
	{
		buf[i++] = ':';
		i += ft_sitoa(&buf[i], dbg.line);
	}
	return (i);
}

static size_t	get_error_message(char *buf, t_error err, t_debug dbg)
{
	size_t	i;
	size_t	copied;

	i = get_syscontext(buf, dbg);
	copied = ft_strlcpy(&buf[i], get_error_info(err), INFO_LIMIT + 1);
	if (copied > INFO_LIMIT)
		i += INFO_LIMIT + ft_strlcpy(&buf[i + INFO_LIMIT], THREE_DOT, 4);
	else
		i += copied;
	buf[i++] = '\n';
	buf[i] = '\0';
	return (i);
}

t_debug	loc(const char *file, int line)
{
	t_debug	dbg;

	dbg.file = file;
	dbg.line = line;
	return (dbg);
}

int	print_error(t_debug dbg, t_error err, int int_code)
{
	char	msg[MSG_LIMIT];
	size_t	size;

	if (err == ERR_NONE)
		return (0);
	if (err == ERR_PERROR)
	{
		get_syscontext(msg, dbg);
		perror(msg);
	}
	else
	{
		size = get_error_message(msg, err, dbg);
		write(2, msg, size);
	}
	return (int_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:06:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:27:19 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/simulation.h"
#include "../include/error.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;

	status = setup_simulation(&sim, argc, argv);
	if (status != EXIT_SUCCESS)
		return (status);
	sim.philos = malloc(sizeof(t_philo) * sim.n_philos);
	if (!sim.philos)
		return (print_error(loc( F, L), ERR_PERROR, ENOMEM));
	sim.forks = malloc(sizeof(pthread_mutex_t) * sim.n_philos);
	if (!sim.forks)
		return (free_sim(&sim), print_error(loc( F, L), ERR_PERROR, ENOMEM));
	init_simulation(&sim);
	status = thread_simulation(&sim);
	cleanup_sim(&sim);
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:45:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 21:14:01 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"

static bool	all_meals_done(t_sim *sim)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (i < sim->n_philos)
	{
		pthread_mutex_lock(&sim->philos[i].last_meal_mutex);
		done += (sim->philos[i].meals_eaten >= sim->meal_goal);
		pthread_mutex_unlock(&sim->philos[i].last_meal_mutex);
		i++;
	}
	return (done == sim->n_philos);
}

void	*monitor(void *arg)
{
	t_sim	*sim;
	int		i;

	sim = (t_sim *)arg;
	while (!get_stop(sim))
	{
		i = 0;
		while (i < sim->n_philos)
		{
			pthread_mutex_lock(&sim->philos[i].last_meal_mutex);
			if (sim->meal_goal > 0 && all_meals_done(sim))
			{
				set_stop(sim, true);
				pthread_mutex_unlock(&sim->philos[i].last_meal_mutex);
				return (NULL);
			}
			if (now_ms() - sim->philos[i].last_meal_time >= sim->time_to_die)
			{
				print_action(&sim->philos[i], DIE);
				set_stop(sim, true);
				pthread_mutex_unlock(&sim->philos[i].last_meal_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&sim->philos[i].last_meal_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:27:20 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:35:57 by mattcarniel      ###   ########.fr       */
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
		i += ft_sitoa(&buf[i], p->id + 1);
		buf[i++] = ' ';
		i += ft_strlcpy(&buf[i], get_action(action), sizeof(buf) - i);
		buf[i++] = '\n';
		buf[i] = '\0';
		write(1, buf, i);
	}
	pthread_mutex_unlock(&p->sim->print_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:48:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:33:41 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/print_action.h"

static void	eat_spaghetti(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->sim->forks[p->right_fork]);
		print_action(p, TAKE_FORK);
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
		pthread_mutex_lock(&p->sim->forks[p->right_fork]);
		print_action(p, TAKE_FORK);
	}
	p->last_meal_time = now_ms();
	print_action(p, EAT);
	ms_sleep(p->sim, p->sim->time_to_eat);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->sim->forks[p->right_fork]);
	pthread_mutex_unlock(&p->sim->forks[p->left_fork]);
}

static void	hit_the_sack(t_philo *p)
{
	print_action(p, SLEEP);
	ms_sleep(p->sim, p->sim->time_to_sleep);
}

static void	have_an_existential_crisis(t_philo *p)
{
	print_action(p, THINK);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->sim->n_philos == 1)
	{
		pthread_mutex_lock(&p->sim->forks[p->left_fork]);
		print_action(p, TAKE_FORK);
		ms_sleep(p->sim, p->sim->time_to_die);
		pthread_mutex_unlock(&p->sim->forks[p->left_fork]);
		return (NULL);
	}
	if (p->id % 2 == 1)
		usleep(1000);
	while (!get_stop(p->sim))
	{
		eat_spaghetti(p);
		hit_the_sack(p);
		have_an_existential_crisis(p);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:28:35 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:30:41 by mattcarniel      ###   ########.fr       */
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
ll	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((ll)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief Sleep for a given number of milliseconds, as long as simulation is running.
 * @param sim simulation pointer
 * @param ms milliseconds to sleep
 */
void	ms_sleep(t_sim *sim, int ms)
{
	ll	t;

	t = now_ms();
	while (!get_stop(sim))
	{
		if (now_ms() - t < ms)
			break ;
		usleep(500);
	}
}

/**
 * @brief Get the stop status of the simulation.
 * @param sim simulation pointer
 * @return true if simulation is stopped, false otherwise.
 */
bool	get_stop(t_sim *sim)
{
	bool	stop;

	stop = sim->stop;
	return (stop);
}
/**
 * @brief Set the stop status of the simulation.
 * @param sim simulation pointer
 * @param value value to set
 */
void	set_stop(t_sim *sim, bool value)
{
	sim->stop = value;
}

/**
 * @brief Check if a philosopher has died.
 * @param p philosopher pointer
 * @return true if philosopher has died, false otherwise.
 */
bool	check_death(t_philo *p)
{
	ll	time_since_last_meal;

	pthread_mutex_lock(&p->last_meal_mutex);
	time_since_last_meal = now_ms() - p->last_meal_time;
	pthread_mutex_unlock(&p->last_meal_mutex);
	return (time_since_last_meal >= p->sim->time_to_die);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:55:43 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/21 15:38:26 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "../include/structures.h"
#include "../include/routine.h"
#include "../include/monitor.h"
#include "../include/error.h"

int	setup_simulation(t_sim *sim, int argc, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;

	if (argc < 5 || argc > 6)
		return (print_error(loc( F, L), ERR_INVALID_ARG_COUNT, EXIT_FAILURE));
	status |= ft_atou_safe(argv[1], &sim->n_philos);
	status |= ft_atou_safe(argv[2], &sim->time_to_die);
	status |= ft_atou_safe(argv[3], &sim->time_to_eat);
	status |= ft_atou_safe(argv[4], &sim->time_to_sleep);
	sim->meal_goal = 0;
	if (argc == 6)
		status |= ft_atou_safe(argv[5], &sim->meal_goal);
	if (status != EXIT_SUCCESS)
		return (print_error(loc( F, L), ERR_INVALID_ARGS, EXIT_FAILURE));
	if (sim->n_philos == 0)
		return (print_error(loc( F, L), ERR_NO_PHILOS, EXIT_FAILURE));
	if (sim->n_philos > MAX_PHILOS)
		return (print_error(loc( F, L), ERR_TOO_MANY_PHILOS, EXIT_FAILURE));
	if ((sim->time_to_die > 0 && sim->time_to_die < MAX_DEATH_TIME)
		|| (sim->time_to_eat && sim->time_to_eat < MAX_EAT_TIME)
		|| sim->time_to_sleep > 0 && sim->time_to_sleep < MAX_SLEEP_TIME)
		return (print_error(loc( F, L), ERR_BAD_VAL, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

void init_simulation(t_sim *sim)
{
	uint	i;

	i = 0;
	sim->threads_created = 0;
	sim->stop = false;
	sim->monitor = false;
	sim->start_time = now_ms();
	pthread_mutex_init(&sim->print_mutex, NULL);
	while (i < sim->n_philos)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].left_fork = i;
		sim->philos[i].right_fork = (i + 1) % sim->n_philos;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].last_meal_time = sim->start_time;
		sim->philos[i].state = THINKING;
		sim->philos[i].sim = sim;
		pthread_mutex_init(&sim->philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
}

int	thread_simulation(t_sim *sim)
{
	int		status;
	
	status = EXIT_SUCCESS;
	status = pthread_create(&sim->monitor_thread, NULL, monitor, &sim);
	if (status)
		return (print_error(loc( F, L), ERR_PERROR, status));
	else
		sim->monitor = true;
	while (sim->threads_created < sim->n_philos)
	{
		status = pthread_create(&sim->philos[sim->threads_created].thread, NULL,
				&routine, &sim->philos[sim->threads_created]);
		if (status)
			return (print_error(loc( F, L), ERR_PERROR, status));
		sim->threads_created++;
	}
	return (status);
}

void	free_sim(t_sim *sim)
{
	if (sim->philos)
		free(sim->philos);
	if (sim->forks)
		free(sim->forks);
}

void	cleanup_sim(t_sim *sim)
{
	uint	i;

	i = 0;
	if (sim->monitor)
		pthread_join(sim->monitor_thread, NULL);
	while (i < sim->threads_created)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < sim->n_philos)
	{
		pthread_mutex_destroy(&sim->philos[i].last_meal_mutex);
		i++;
	}
	i = 0;
	while (i < sim->n_philos)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	free_sim(sim);
}
