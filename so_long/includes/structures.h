/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:01:59 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/15 16:03:39 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_coords
{
	size_t	x;
	size_t	y;
}				t_coords;

typedef struct	s_map {
	char		**grid;
	size_t		width;
	size_t		height;
	t_coords	player;
	t_coords	exit;
	t_list		*collectibles;
}				t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game
{
	t_map		*map;
	void		*mlx;
	void		*win;
}				t_game;

#endif