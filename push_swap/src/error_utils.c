/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:31:39 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 17:53:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "structures.h"
#include "error_utils.h"

#define SUCCESS_MSG	"OK\n"
#define FAILURE_MSG	"KO\n"
#define ERROR_MSG		"Error\n"
#define UNKOWN_MSG		"Unknown\n"

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

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (false);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value >= current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
