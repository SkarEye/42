/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:37:59 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 16:39:03 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

# include <stdbool.h>

# ifndef SILENT
#  define SILENT	false
# endif

# define ERR_LOC	__FILE__, __LINE__

typedef enum e_error
{
	ERR_NONE,
	ERR_BAD_ARGS,
	ERR_BAD_ESC,
	ERR_START_QUOTE,
	ERR_END_QUOTE,
	ERR_BAD_FIND,
	ERR_BAD_PARSE,
	ERR_NO_CMD,
	ERR_BAD_EXECVE,
	ERR_UNKNOWN,
	ERR_COUNT,
	ERR_PERROR
} t_error;

void	print_error(const char *file, int line, t_error err, bool is_silent);

#endif