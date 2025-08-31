/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:14:01 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/31 14:28:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

# include "structures.h"

void	bresenham_line(t_pixel a, t_pixel b, t_fdf *fdf);
t_pixel	project(t_point p, t_fdf *fdf);

#endif