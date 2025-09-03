/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:27:31 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/03 19:59:26 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

# define PXL_W	800
# define PXL_H	600

typedef struct s_point
{
	int 	x;
	int		y;
	int		z;
	
	unsigned int	color;
}			t_point;

typedef struct s_pov
{
	double	x;
	double	y;
	double	z;

	double	u;
	double	v;
	double	w;

	double	fov;
}			t_pov;

typedef struct s_pixel
{
	int		x;
	int		y;

	unsigned int	color;
}			t_pixel;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		pxl_w;
	int		pxl_h;
	int		bits_pxl;
	int		line_length;
	int		endian;
}			t_data;

typedef enum e_state
{
	START,
	MENU,
	FDF,
	PAUSE,
	COUNT
}			t_state;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;

	t_data	*data;
	t_data	*base;

	t_state	state;

	char	*stash;
	char	*line;

	t_pov	cam;

	size_t	map_w;
	size_t	map_h;
	t_point	*map;
}			t_fdf;

#endif