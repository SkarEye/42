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