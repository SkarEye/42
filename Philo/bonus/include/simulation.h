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