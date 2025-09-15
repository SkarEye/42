/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:14:01 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/15 18:48:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

# include "structures.h"

void	get_matrix(t_pov *cam);
void	project(t_point *point, t_pov cam);

void	bresenham(t_pixel a, t_pixel b, unsigned int c, t_fdf *fdf);

void	draw_text(const char *str, t_pos2d pos, t_txt txt, t_fdf *fdf);

void	draw_gyroscope(t_pos2d pos, int scale, t_fdf *fdf);

void	draw_fdf(t_pov cam, unsigned int c, t_fdf *fdf);
void	draw_3d(t_fdf *fdf);

#endif