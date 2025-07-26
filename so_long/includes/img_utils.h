/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:41:00 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 17:08:13 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H

# include "structures.h"

unsigned int	get_pixel_color(t_data *data, int x, int y);
void		 	set_pixel_color(t_data *data, int x, int y, int color);
void			scale_pixel(t_data *dst, int x, int y, int color, int scale);

unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, double a);

void			clear_image(t_data *img);
void			free_image(void *mlx, t_data *data);	
t_data			*make_blank_image(void *mlx, int width, int height);
t_data			*get_image_from_xpm(void *mlx, char *filename);

void			paste_image(t_data *dst, t_data *src, int x, int y);
void			scale_image(void *mlx, t_data **img, int scale);
void			outline_image(t_data *img, int size, unsigned int color);

void			draw_square(t_data *dst, int x, int y, int color, int scale);

#endif