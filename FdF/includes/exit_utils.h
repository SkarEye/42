/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:34:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/27 13:35:54 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_UTILS_H
# define EXIT_UTILS_H

# include <stddef.h>

# include "structures.h"
# include "error_utils.h"

void	exit_fdf(t_debug dbg, t_error err, int exit_code, t_fdf *fdf);

void	*xmalloc(size_t size, t_debug dbg, t_fdf *fdf);
void	*xcalloc(size_t size, t_debug dbg, t_fdf *fdf);
// int		xopen(int *fd, const char *filename, int flags, t_debug
// 		dbg, t_fdf *fdf);
void	xclose(int *fd, t_debug dbg, t_fdf *fdf);

#endif