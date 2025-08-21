/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:56:06 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 15:48:09 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(~n + 1));
	return ((unsigned int)n);
}

int	count_min_steps(t_stack *stack, size_t index)
{
	int		steps_forwards;
	int		steps_backwards;
	t_node	*node;

	steps_forwards = 0;
	node = stack->head;
	while (node && node->index != index)
	{
		steps_forwards++;
		node = node->next;
	}
	steps_backwards = -1;
	node = stack->tail;
	while (node && node->index != index)
	{
		steps_backwards--;
		node = node->prev;
	}
	if (-steps_forwards > steps_backwards)
		return (steps_forwards);
	else
		return (steps_backwards);
}

void	get_to_index(t_stack *stack, int steps,
	void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *))
{
	while (steps > 0)
	{
		rotate(stack);
		steps--;
	}
	while (steps < 0)
	{
		rev_rotate(stack);
		steps++;
	}
}

int	is_index_in_stack(t_stack *stack, size_t index)
{
	t_node	*current;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->index == index)
			return (1);
		current = current->next;
	}
	return (0);
}
