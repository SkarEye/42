/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:50:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/23 15:01:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>

# include "get_next_line.h"

//messages
# define INVALID_READ "Could not read file\n"
# define INVALID_TEXT_FILE "The given file cannot bet made into a rectangular map.\n"
# define INVALID_MALLOC "Memory allocation failed\n"

typedef struct	s_coords {
	size_t	x;
	size_t	y;
}				t_coords;

typedef struct	s_map {
	char		**grid;
	size_t		width;
	size_t		height;
	t_list		*collectibles;
	t_coords	*player;
	t_coords	*exit;
}				t_map;

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;


//flood_fill.c
char	is_valid_path
char	is_valid_map

#endif