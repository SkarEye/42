/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:56:06 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:28:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "utils/algo_helper.h"

void	three_sort(t_stack *stack, void (*swap)(t_stack *),
		void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *))
{
	if (!stack || stack->size != 3)
		return ;
	if (stack->head->index > stack->head->next->index
		&& stack->head->index > stack->tail->index)
		rotate(stack);
	else if (stack->head->next->index > stack->head->index
		&& stack->head->next->index > stack->tail->index)
		rev_rotate(stack);
	if (stack->head->index > stack->head->next->index)
		swap(stack);
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
	if (ft_abs(steps_forwards) <= ft_abs(steps_backwards))
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

size_t	find_max_index(t_stack *stack)
{
	t_node	*current;
	size_t	max_index;

	if (!stack || !stack->size)
		return (0);
	current = stack->head;
	max_index = 0;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

size_t	find_min_index(t_stack *stack)
{
	t_node	*current;
	size_t	min_index;

	if (!stack || !stack->size)
		return (0);
	current = stack->head;
	min_index = stack->size - 1;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}
