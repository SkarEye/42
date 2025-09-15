/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:27:31 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/15 18:35:46 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>
# include <stdbool.h>

# define PXL_W	800
# define PXL_H	600


# define G_W			8
# define G_H			8
# define FONT_ROW_SIZE	32

# define D_PROJ	PROJ_ISO
# define D_CAM	CAM_ISO
# define D_COL	COL_DEF

typedef struct s_vect3d
{
	float 	x;
	float	y;
	float	z;
}			t_vect3d;

typedef struct s_pos2d
{
	int	x;
	int	y;
}		t_pos2d;

typedef struct s_pixel
{
	t_pos2d			p;
	unsigned int	c;
	bool			is_valid;
}					t_pixel;

typedef struct s_point
{
	t_vect3d		v;
	t_pixel			l;
}					t_point;

typedef struct s_pov
{
	t_vect3d	v;
	t_vect3d	r;

	float		m[3][3];

	float		fov;
	float		focal;

	int			is_fish;
	int			is_3d;
}			t_pov;

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
	t_pos2d			size;
	unsigned int	color;
	int				scale;
	t_align			align;
}		t_txt;

typedef enum e_state
{
	START,
	FDF,
	COUNT
}			t_state;

typedef	enum e_cam
{
	CAM_ISO,
	CAM_VER,
	CAM_HOR,
	CAM_COUNT
}			t_cam;

typedef	enum e_proj
{
	PROJ_FDF,
	PROJ_3D,
	PROJ_EYE,
	PROJ_COUNT
}			t_proj;

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

	t_proj			proj_type;
	t_cam			cam_type;

	t_pov			cam;
	t_pov			inertia;

	size_t			map_w;
	size_t			map_h;
	t_point			*map;
}			t_fdf;

t_vect3d	set_vect3d(float x, float y, float z);
t_pov		set_pov(t_vect3d v, t_vect3d r, float fov);
t_txt		set_txt(t_pos2d size, unsigned int color, int scale, t_align align);

void		set_vertical(t_fdf *fdf);
void		set_horizontal(t_fdf *fdf);
void		set_isometric(t_fdf *fdf);

#endif