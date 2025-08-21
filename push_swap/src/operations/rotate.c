/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:30:22 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 18:27:00 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "operations.h"
#include "utils/node_utils.h"

static void    rotate(t_stack *stack)
{
	t_node *node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	node = pop_node_front(stack);
	add_to_back(stack, node);
}

void    ra(t_stack *a)
{
	rotate(a);
	write(1, RA, 3);
}

void    rb(t_stack *b)
{
	rotate(b);
	write(1, RB, 3);
}

void    rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, RR, 3);
}
