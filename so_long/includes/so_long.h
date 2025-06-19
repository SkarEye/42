/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:50:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/19 16:17:10 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>

# include "get_next_line.h"

//messages
# define INVALID_READ_MSG "Could not read file\n"

typedef struct	s_coords {
	size_t	x;
	size_t	y;
}				t_coords;

typedef struct	s_map {
	char		**grid;
	size_t		width;
	size_t		height;
	t_coords	*collectibles;
	t_coords	player;
	t_coords	exit;
}				t_map;

//flood_fill.c
char	is_valid_path
char	is_valid_map

#endif