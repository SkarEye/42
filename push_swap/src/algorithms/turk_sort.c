/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:37:39 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:26 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "structures.h"
#include "operations.h"
#include "utils/algo_helper.h"

static size_t	find_target_index(t_stack *stack, size_t index)
{
	t_node	*node;
	t_node	*best;

	if (!stack || !stack->size)
		return (0);
	node = stack->head;
	best = NULL;
	while (node)
	{
		if (node->index > index && (!best || node->index < best->index))
			best = node;
		node = node->next;
	}
	if (!best)
		return (find_min_index(stack));
	return (best->index);
}

static void	calculate_costs(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		steps_a;
	int		steps_b;

	if (!b->size)
		return ;
	current = b->head;
	while (current)
	{
		steps_a = count_min_steps(a, find_target_index(a, current->index));
		steps_b = count_min_steps(b, current->index);
		if ((steps_a < 0 && steps_b < 0) || (steps_a > 0 && steps_b > 0))
			current->cost = ft_max(ft_abs(steps_a), ft_abs(steps_b));
		else
			current->cost = ft_abs(steps_a) + ft_abs(steps_b);
		current = current->next;
	}
}

static t_node	*find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*best;

	if (!b->size)
		return (NULL);
	calculate_costs(a, b);
	current = b->head;
	best = current;
	while (current)
	{
		if (current->cost < best->cost)
			best = current;
		current = current->next;
	}
	return (best);
}

static void	rotate_stacks(t_stack *a, t_stack *b)
{
	t_node	*best;
	int		steps_a;
	int		steps_b;

	best = find_cheapest(a, b);
	if (!best)
		return ;
	steps_a = count_min_steps(a, find_target_index(a, best->index));
	steps_b = count_min_steps(b, best->index);
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

void	turk_sort(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2)
		return ;
	while (a->size > 3)
		pb(a, b);
	three_sort(a, sa, ra, rra);
	while (b->size)
	{
		rotate_stacks(a, b);
		pa(a, b);
	}
	get_to_index(a, count_min_steps(a, 0), ra, rra);
}
