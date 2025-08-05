/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:26:36 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 17:29:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "error_utils.h"

char    *make_arg(char *args)
{
    
}

char	**split_args(char *args)
{
	char	**split;
	char	*ptr;
	ssize_t	count;
	size_t	n;

	count = count_args(args);
	if (count < 0)
		return (print_error(ERR_LOC, ERR_BAD_ARGS, false), NULL);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (print_error(ERR_LOC, ERR_PERROR, false), NULL);
	n = 0;
	while (n < (size_t)count)
	{
		while (*args == ' ' || *args == '\t' || *args == '\n')
			args++;
		ptr = args;
		split[n] = (char *)malloc(sizeof(char) * (parse_arg(&ptr, NULL) + 1));
		if (!split[n] || parse_arg(&args, split[n++]) < 0)
			return (print_error(ERR_LOC, ERR_PERROR, false), free_split(split), NULL); //line too long :(
	}
	split[n] = NULL;
	return (split);
}