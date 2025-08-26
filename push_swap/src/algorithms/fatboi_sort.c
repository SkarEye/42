/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatboi_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:55:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/25 12:39:02 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "operations.h"
#include "utils/algo_helper.h"

static size_t	dynamic_chunk_size(t_stack *stack, size_t index)
{
	if (stack->size <= 100)
		return (15);
	else if (index < stack->size / 2)
		return (45);
	else
		return (30);
}

static int	fb_find_closest(t_stack *stack, size_t index, size_t chunk_size)
{
	t_node	*node;
	int		steps_rotate;
	int		steps_reverse_rotate;

	steps_rotate = 0;
	steps_reverse_rotate = -1;
	node = stack->head;
	while (!(node->index >= index && node->index < index + chunk_size))
	{
		node = node->next;
		steps_rotate++;
	}
	node = stack->tail;
	while (!(node->index >= index && node->index < index + chunk_size))
	{
		node = node->prev;
		steps_reverse_rotate--;
	}
	if (steps_rotate <= -steps_reverse_rotate)
		return (steps_rotate);
	else
		return (steps_reverse_rotate);
}

void	fb_get_to_index(t_stack *a, t_stack *b, int steps_a, int steps_b)
{
	while (steps_a > 0 && steps_b > 0)
	{
		rr(a, b);
		steps_a--;
		steps_b--;
	}
	while (steps_a < 0 && steps_b < 0)
	{
		rrr(a, b);
		steps_a++;
		steps_b++;
	}
	get_to_index(a, steps_a, ra, rra);
	get_to_index(b, steps_b, rb, rrb);
}

static size_t	fb_push_chunk(t_stack *a, t_stack *b, size_t ix, size_t chunk)
{
	size_t	i;
	size_t	steps_a;
	size_t	steps_b;

	i = 0;
	while (a->size > 0 && i < chunk)
	{
		steps_a = fb_find_closest(a, ix, chunk);
		if (b->size > 0)
			steps_b = count_min_steps(b, find_max_index(b));
		else
			steps_b = 0;
		fb_get_to_index(a, b, steps_a, steps_b);
		pb(a, b);
		if (b->head->index < ix + chunk / 2)
			rb(b);
		i++;
	}
	return (ix + i);
}

void	fatboi_sort(t_stack *a, t_stack *b)
{
	size_t	max_index;
	size_t	index;
	size_t	chunk_size;

	if (!a || !b || a->size < 2)
		return ;
	max_index = a->size - 1;
	index = 0;
	while (index <= max_index)
	{
		chunk_size = dynamic_chunk_size(a, index);
		index = fb_push_chunk(a, b, index, chunk_size);
	}
	while (b->size > 0)
	{
		get_to_index(b, count_min_steps(b, max_index), rb, rrb);
		pa(a, b);
		max_index--;
	}
}
