/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:20:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/26 16:48:01 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "../include/error.h"
#include "../include/utils.h"

#define NO_FILE_CONTEXT 	"no file context"
#define THREE_DOT			"..."

#define MSG_LIMIT			128
#define FILE_LIMIT			16
#define INFO_LIMIT			96

static const char	*get_error_info(t_error err)
{
	static const char	*info[] = {
	[ERR_NONE] = ": Success",
	[ERR_INVALID_ARG_COUNT] = " : Invalid number of arguments",
	[ERR_INVALID_ARGS] = " : Invalid arguments given",
	[ERR_NO_PHILOS] = " : Simulation must have at least ONE philosopher",
	[ERR_TOO_MANY_PHILOS] = " : Simulation has too many philosophers to handle",
	[ERR_BAD_VAL] = " : One or more of the values are outside of their scope",
	[ERR_PERROR] = " : System error",
	[ERR_UNKNOWN] = " : Unknown error"
	};

	if (err < 0 || err >= ERR_COUNT)
		return (info[ERR_UNKNOWN]);
	return (info[err]);
}

static size_t	get_syscontext(char *buf, t_debug dbg)
{
	size_t	i;

	i = ft_strlcpy(buf, dbg.file, FILE_LIMIT + 1);
	if (i > FILE_LIMIT)
		i = FILE_LIMIT + ft_strlcpy(&buf[FILE_LIMIT], THREE_DOT, 4);
	if (dbg.line > 0)
	{
		buf[i++] = ':';
		i += ft_sitoa(&buf[i], dbg.line);
	}
	return (i);
}

static size_t	get_error_message(char *buf, t_error err, t_debug dbg)
{
	size_t	i;
	size_t	copied;

	i = get_syscontext(buf, dbg);
	copied = ft_strlcpy(&buf[i], get_error_info(err), INFO_LIMIT + 1);
	if (copied > INFO_LIMIT)
		i += INFO_LIMIT + ft_strlcpy(&buf[i + INFO_LIMIT], THREE_DOT, 4);
	else
		i += copied;
	buf[i++] = '\n';
	buf[i] = '\0';
	return (i);
}

t_debug	loc(const char *file, int line)
{
	t_debug	dbg;

	dbg.file = file;
	dbg.line = line;
	return (dbg);
}

int	print_error(t_debug dbg, t_error err, int int_code)
{
	char	msg[MSG_LIMIT];
	size_t	size;

	if (err == ERR_NONE)
		return (0);
	if (err == ERR_PERROR)
	{
		get_syscontext(msg, dbg);
		perror(msg);
	}
	else
	{
		size = get_error_message(msg, err, dbg);
		write(2, msg, size);
	}
	return (int_code);
}
