/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:47:46 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 19:31:26 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "structures.h"

int	cleanup_simulation(t_sim *sim, int status);
int	setup_simulation(t_sim *sim, int argc, char **argv);

#endif