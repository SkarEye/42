/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:27:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/21 16:15:24 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "operations.h"
#include "utils/node_utils.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = pop_node_front(stack);
	second = pop_node_front(stack);
	add_to_front(stack, first);
	add_to_front(stack, second);
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, SA, 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, SB, 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, SS, 3);
}
