/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:48:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/11 17:10:27 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_UTILS_H
# define EXIT_UTILS_H

# include "structures.h"

typedef enum e_error
{
	ERR_NONE,
	ERR_INVALID_MAP,
	ERR_INVALID_WALLS,
	ERR_TOO_MANY_PLAYERS,
	ERR_NO_PLAYER,
	ERR_TOO_MANY_EXITS,
	ERR_NO_EXIT,
	ERR_NO_COLLECTIBLES,
	ERR_INVALID_CHAR,
	ERR_NOT_RECT,
	ERR_FLOOD_FAIL,
	ERR_MALLOC,
	ERR_OPEN,
	ERR_READ,
	ERR_NO_FILENAME,
	ERR_MLX,
	ERR_EXTENSION,
	ERR_UNKNOWN,
	ERR_COUNT
} t_error;

void	print_error(t_error err, const char *sys_context);
void	exit_game(t_error err, const char *sys_context, t_game *game);

#endif