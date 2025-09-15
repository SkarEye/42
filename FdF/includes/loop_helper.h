/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:10:16 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/10 14:25:45 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HELPER_H
# define LOOP_HELPER_H

# include "structures.h"

void	render_start(t_fdf *fdf);
void	handle_start(int key, t_fdf *fdf);

void	render_fdf(t_fdf *fdf);
void	handle_fdf(int key, t_fdf *fdf);

#endif