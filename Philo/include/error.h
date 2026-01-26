/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:45:04 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 11:41:59 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct s_debug
{
	const char	*file;
	int			line;

	char		reserved[4];
}				t_debug;

# define F	__FILE__
# define L	__LINE__

typedef enum	e_error
{
	ERR_NONE,
	ERR_INVALID_ARG_COUNT,
	ERR_INVALID_ARGS,
	ERR_NO_PHILOS,
	ERR_TOO_MANY_PHILOS,
	ERR_BAD_VAL,
	ERR_PERROR,
	ERR_UNKNOWN,
	ERR_COUNT
}
	t_error;

t_debug	loc(const char *file, int line);
int		print_error(t_debug dbg, t_error err, int int_code);

#endif