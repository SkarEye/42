/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:47:46 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/29 16:17:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "structures.h"

void	cleanup_mallocs(t_sim *sim);
void	cleanup_semaphores(t_sim *sim);
int		setup_simulation(t_sim *sim, int argc, char **argv);

#endif