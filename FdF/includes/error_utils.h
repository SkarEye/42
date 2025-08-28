/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:21:37 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 12:28:39 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

# include <stdbool.h>

typedef struct s_debug
{
	const char	*file;
	int			line;

	char		reserved[4];
}				t_debug;

# define F	__FILE__
# define L	__LINE__

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
	ERR_COUNT,
	ERR_PERROR
}	t_error;

t_debug	loc(const char *file, int line);
void	print_error(t_debug dbg, t_error err, bool is_silent);

#endif
