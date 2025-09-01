/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:14:01 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/01 11:11:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

# include "structures.h"

void	bresenham_line(t_pixel a, t_pixel b, t_fdf *fdf);

void	set_cam(double pos[3], double ang[3], double fov, t_fdf *fdf);
void	set_isometric_cam(t_fdf *fdf);
void	set_spawned_cam(t_fdf *fdf);

t_pixel	project(t_point p, t_fdf *fdf);

#endif