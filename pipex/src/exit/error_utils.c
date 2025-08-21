/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:27:38 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 18:51:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#include "error_utils.h"

#define NO_FILE_CONTEXT 	"no file context"
#define THREE_DOT			"..."

#define MSG_LIMIT			128
#define FILE_LIMIT			16
#define INFO_LIMIT			96

static const char	*get_error_info(t_error err)
{
	const char	*error_info[] = {
		": Success !\n",
		": Invalid arguments.\n",
		": Invalid 'Escape' character.\n",
		": Missing starting double quote.\n",
		": Missing ending double quote.\n",
		": No paths found.\n",
		": Parsing failed.\n",
		": Command not found.\n",
		": execve failed.\n",
		": Tried exiting child process while in parent.\n",
		": Tried exiting parent process while in child.\n",
		": Unknown error.\n"
	};

	if (err < 0 || err >= ERR_COUNT)
		return (error_info[ERR_UNKNOWN]);
	return (error_info[err]);
}

static size_t	get_syscontext(char *sys_context, t_debug dbg)
{
	size_t	i;

	i = ft_strlcpy(sys_context, dbg.file, FILE_LIMIT + 1);
	if (i > FILE_LIMIT)
		i = FILE_LIMIT + ft_strlcpy(&sys_context[FILE_LIMIT], THREE_DOT, 4);
	if (dbg.line > 0)
	{
		sys_context[i++] = ':';
		i += ft_sitoa(&sys_context[i], dbg.line);
	}
	return (i);
}

static size_t	get_error_message(char *err_msg, t_error err, t_debug dbg)
{
	size_t	i;
	size_t	copied;

	i = get_syscontext(err_msg, dbg);
	copied = ft_strlcpy(&err_msg[i], get_error_info(err), INFO_LIMIT + 1);
	if (copied > INFO_LIMIT)
		i += INFO_LIMIT + ft_strlcpy(&err_msg[i + INFO_LIMIT], THREE_DOT, 4);
	else
		i += copied;
	return (i);
}

t_debug	loc(const char *file, int line)
{
	t_debug	dbg;

	dbg.file = file;
	dbg.line = line;
	return (dbg);
}

void	print_error(t_debug dbg, t_error err, bool is_silent)
{
	char	str[MSG_LIMIT];
	size_t	size;

	if (is_silent || err == ERR_NONE)
		return ;
	if (err == ERR_PERROR)
	{
		get_syscontext(str, dbg);
		return (perror(str));
	}
	else
	{
		size = get_error_message(str, err, dbg);
		write(2, str, size);
	}
}
