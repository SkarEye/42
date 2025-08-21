/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:31:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 18:27:14 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "operations.h"
#include "utils/node_utils.h"

static void	rev_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->tail || !stack->tail->prev)
		return ;
	node = pop_node_back(stack);
	add_to_front(stack, node);
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	write(1, RRA, 4);
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	write(1, RRB, 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, RRR, 4);
}
