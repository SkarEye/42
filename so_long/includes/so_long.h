/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:50:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/09 17:02:37 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define INVALID_READ "Could not read file\n"
# define INVALID_TEXT_FILE "File cannot be made into a rectangular map.\n"
# define INVALID_MALLOC "Memory allocation failed\n"
# define TOO_MANY_START_POS "Too many starting positions (P) in the map.\n"
# define TOO_MANY_EXIT "Too many exit positions (E) in the map.\n"
# define INVALID_CHAR "Invalid character in map.\n"
# define INVALID_SETUP "Map setup is invalid.\n"


#endif