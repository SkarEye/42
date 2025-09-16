/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:13:20 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:14:05 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "structures.h"

void			set_pixel(t_pos2d pos, unsigned int color, t_data *data);
void			add_pixel(t_pos2d pos, unsigned int color, t_data *data);
unsigned int	get_pixel(t_pos2d pos, t_data *data);
void			scale_pixel(t_pos2d p, unsigned int c, int scale, t_data *dst);
unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, float t);

void			clear_image(t_data *img);
void			free_image(void *mlx, t_data *data);
t_data			*make_blank_image(void *mlx, int width, int height);
t_data			*get_image_from_xpm(void *mlx, char *file);

#endif