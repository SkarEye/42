/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:27:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/05 18:10:27 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#include "error_utils.h"

#define NO_FILE_CONTEXT 	"no file context"
#define NO_ERR_MSG			"Could not get error message.\n"

static char	*get_syscontext(t_debug dbg)
{
	char	*syscontext;
	char	*str_line;

	if (!dbg.file)
		return (NULL);
	str_line = ft_itoa(dbg.line);
	if (!str_line)
		return (NULL);
	syscontext = ft_join(dbg.file, str_line, ':');
	free(str_line);
	if (!syscontext)
		return (NULL);
	return (syscontext);
}

static const char	*get_error_info(t_error err)
{
	const char *error_info[] = {
		": Success !\n",
		": Invalid arguments.\n",
		": Invalid 'Esacpe' character.\n",
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

static char	*get_error_message(const char *syscontext, t_error err)
{
	if (!syscontext)
		return (ft_join(NO_FILE_CONTEXT, get_error_info(err), '\0'));
	else
		return (ft_join(syscontext, get_error_info(err), '\0'));
}

void	print_error(t_debug dbg, t_error err, bool is_silent)
{
	char	*syscontext;
	char	*err_msg;

	if (is_silent || err == ERR_NONE)
		return ;
	syscontext = get_syscontext(dbg);
	err_msg = get_error_message(syscontext, err);
	if (err == ERR_PERROR)
	{
		if (syscontext)
			perror(syscontext);
		else
			perror(NO_FILE_CONTEXT);
	}
	else
	{
		if (err_msg)
			write(2, err_msg, ft_strlen(err_msg));
		else
			write(2, NO_ERR_MSG, ft_strlen(NO_ERR_MSG));
	}
	if (syscontext)
		free(syscontext);
	if (err_msg)
		free(err_msg);
}
