/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:34:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 16:52:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_UTILS_H
# define EXIT_UTILS_H

# include <stddef.h>

# include "structures.h"

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
	ERR_NO_FILENAME,
	ERR_INVALID_MAP,
	ERR_UNKNOWN,
	ERR_COUNT,
	ERR_PERROR
}	t_error;

t_debug	loc(const char *file, int line);
void	print_error(t_debug dbg, t_error err, bool is_silent);

void	exit_fdf(t_debug dbg, t_error err, int exit_code, t_fdf *fdf);

void	*xmalloc(size_t size, t_debug dbg, t_fdf *fdf);
void	*xcalloc(size_t size, t_debug dbg, t_fdf *fdf);
char	**xsplit(const char *s, char c, t_debug dbg, t_fdf *fdf);
void	xfree(void **ptr);
int		xopen(const char *filename, int flags, t_debug dbg, t_fdf *fdf);
void	xclose(int *fd, t_debug dbg, t_fdf *fdf);

#endif