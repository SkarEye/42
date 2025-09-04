/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:27:31 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:29:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

# define PXL_W	800
# define PXL_H	600


# define G_W			8
# define G_H			8
# define FONT_ROW_SIZE	32

typedef struct s_vect3d
{
	float 	x;
	float	y;
	float	z;
}			t_vect3d;

typedef struct s_pov
{
	t_vect3d	p;
	t_vect3d	a;

	float		fov;
}			t_pov;

typedef struct s_pixel
{
	int		x;
	int		y;
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

typedef enum e_align
{
	A_LEFT,
	A_RIGHT,
	A_CENTERED,
	A_JUSTIFIED,
	A_UNKNOWN
}		t_align;

typedef struct e_txt
{
	t_pixel			size;
	unsigned int	color;
	int				scale;
	t_align			align;
}		t_txt;


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
	void			*mlx;
	void			*win;

	t_data			*data;
	t_data			*base;
	t_data			*font;

	t_state			state;

	char			*stash;
	char			*line;

	t_pov			cam;

	size_t			map_w;
	size_t			map_h;
	t_vect3d		*map;
	unsigned int 	*colors;
}			t_fdf;

t_vect3d	set_vect3d(float x, float y, float z);
t_pov		set_pov(t_vect3d pos, t_vect3d ang, float fov);
t_txt		set_txt(t_pixel size, unsigned int color, int scale, t_align align);

#endif