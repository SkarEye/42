/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:01:59 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:48:35 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

# ifndef MAX_IMAGES
#  define MAX_IMAGES 32
# endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_coords
{
	int				x;
	int				y;
}				t_coords;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		p_w;
	int		p_h;
	int		bits_pxl;
	int		line_length;
	int		endian;
}				t_data;

typedef enum	e_align {
	A_LEFT,
	A_CENTERED,
	A_RIGHT,
	A_JUSTIFIED
}				t_align;

typedef struct s_text_info {
	int			width;
	int			height;
	int			color;
	t_align		align;
}				t_text_info;

typedef struct	s_map {
	char		**grid;
	int			width;
	int			height;
	t_coords	player;
	t_coords	exit;
	t_list		*collectibles;
}				t_map;

typedef enum	e_img_id {
	IMG_FONT,
	IMG_INIT_PARAGRAPH,
	IMG_INIT_PAR2,
	IMG_TITLE,
	IMG_CLAIRE,
	IMG_POOL_END
}				t_img_id;

typedef enum	e_state
{
	STATE_INIT,
	STATE_START,
	STATE_MENU,
	STATE_LOADING,
	STATE_PLAYING,
	STATE_GAME_OVER,
	STATE_EXIT
}				t_state;

typedef struct	s_game
{
	t_map		*map;
	size_t		p_w;
	size_t		p_h;
	void		*mlx;
	void		*win;
	t_data		*data;
	t_data		*base;
	t_data		**pool;
	t_state		state;
	double		alpha;
	double		beta;
}				t_game;

#endif