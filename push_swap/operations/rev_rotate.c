/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:31:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/03 19:32:32 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rev_rotate(t_stack *stack)
{
    t_node *node;

    if (!stack || !stack->tail || !stack->tail->prev)
        return ;
    node = pop_node_back(stack);
    add_to_front(stack, node);
}

void    rra(t_stack *a) { rev_rotate(a); }

void    rrb(t_stack *b) { rev_rotate(b); }

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
