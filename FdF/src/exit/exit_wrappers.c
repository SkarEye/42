/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wrappers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:31:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 18:01:29 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "structures.h"
#include "utils.h"
#include "exit_utils.h"

/**
 * @brief Wrapper function for 'malloc' that safely exits program on error.
 *
 * @param size Bytes of memory
 * @param dbg Filename and line value
 * @param fdf FDF struct pointer
 * @return Malloc'ed pointer
 */
void	*xmalloc(size_t size, t_debug dbg, t_fdf *fdf)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (ptr);
}

/**
 * @brief Wrapper function for 'malloc' that safely exits program on error.
 *
 * @param size Bytes of memory
 * @param dbg Filename and line value
 * @param fdf FDF struct pointer
 * @return Calloc'ed pointer
 * @note On success, sets all malloc'ed bytes to zero.
 */
void	*xcalloc(size_t size, t_debug dbg, t_fdf *fdf)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	ft_bzero(ptr, size);
	return (ptr);
}

/**
 * @brief Wrapper function for 'ft_split' that safely exits program on error.
 *
 * @param s Character string
 * @param c Character seperator
 * @param dbg Filename and line value
 * @param fdf FDF struct pointer
 * @return A character string array split by 'c'.
 * @note See ft_split for its brief.
 */
char	**xsplit(const char *s, char c, t_debug dbg, t_fdf *fdf)
{
	char	**ptr;

	ptr = ft_split(s, c);
	if (!ptr)
		exit_fdf(dbg, ERR_PERROR, 1, fdf);
	return (ptr);
}

/**
 * @brief Wrapper function for 'free' that always sets the given pointer to
 * NULL.
 *
 * @param ptr Pointer to the malloc'ed address
 */
void	xfree(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
