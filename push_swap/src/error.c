/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:31:39 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:40:43 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "error_utils.h"

# define SUCCESS_MSG	"OK\n"
# define FAILURE_MSG	"KO\n"
# define ERROR_MSG		"Error\n"
# define UNKOWN_MSG		"Unknown\n"

void	print_error(t_result res)
{
	if (res == SUCCESS)
		write(1, SUCCESS_MSG, 3);
	else if (res == FAILURE)
		write(1, FAILURE_MSG, 3);
	else if (res == ERROR)
		write(2, ERROR_MSG, 6);
	else
		write(2, UNKOWN_MSG, 8);
}