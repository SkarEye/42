/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:27:31 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/30 18:48:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

typedef struct s_point
{
	int x;
	int	y;
	int	z;
	
	int	color;
}	t_point;

typedef struct s_pixel
{
	int	x;
	int	y;

	int	color;
}	t_pixel;

typedef struct s_b_line
{
	t_pixel	dp;
	t_pixel	ds;

	int	

}

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		pxl_w;
	int		pxl_h;
	int		bits_pxl;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;

	t_data	*data;
	t_data	*base;

	char	*stash;
	char	*line;

	size_t	map_w;
	size_t	map_h;
	t_point	*map;
}	t_fdf;

#endif