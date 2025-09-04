/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:13:20 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:25:18 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "structures.h"

void			set_pixel(t_pixel p, unsigned int color, t_data *data);
unsigned int	get_pixel(t_pixel p, t_data *data);
void			scale_pixel(t_pixel p, unsigned int color, int scale, t_data *dst);
unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, float t);

void			clear_image(t_data *img);
void			free_image(void *mlx, t_data *data);
t_data			*make_blank_image(void *mlx, int width, int height);
t_data			*get_image_from_xpm(void *mlx, const char *file);
void			paste_image(t_pixel p, int scale, t_data *src, t_data *dst);
void			outline_image(int size, unsigned int color, t_data *img);

void			draw_text(const char *str, t_pixel p, t_txt txt, t_fdf *fdf);

#endif