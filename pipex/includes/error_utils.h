/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:37:59 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/21 19:44:55 by macarnie         ###   ########.fr       */
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
	ERR_BAD_ARGS,
	ERR_BAD_ESC,
	ERR_START_QUOTE,
	ERR_END_QUOTE,
	ERR_NO_PATH,
	ERR_BAD_PARSE,
	ERR_NO_CMD,
	ERR_BAD_EXECVE,
	ERR_CHILD_EXIT,
	ERR_PARENT_EXIT,
	ERR_UNKNOWN,
	ERR_COUNT,
	ERR_PERROR
}	t_error;

t_debug	loc(const char *file, int line);
void	print_error(t_debug dbg, t_error err, bool is_silent);

#endif