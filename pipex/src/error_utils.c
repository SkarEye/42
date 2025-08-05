/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:27:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 15:34:51 by mattcarniel      ###   ########.fr       */
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

static char	*get_syscontext(const char *file, int line)
{
	char	*syscontext;
	char	*str_line;

	if (!file)
		return (NULL);
	str_line = ft_itoa(line);
	if (!str_line)
		return (NULL);
	syscontext = ft_join(file, str_line, ':');
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
		": No valid result found.\n",
		": Parsing failed.\n",
		": Command not found.\n",
		": execve failed.\n",
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

void	print_error(const char *file, int line, t_error err, bool is_silent)
{
	char	*syscontext;
	char	*err_msg;

	if (is_silent)
		return ;
	syscontext = get_syscontext(file, line);
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
