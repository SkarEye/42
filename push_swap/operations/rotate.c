/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:30:22 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/03 19:31:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack *stack)
{
    t_node *node;

    if (!stack || !stack->head || !stack->head->next)
        return ;
    node = pop_node_front(stack);
    add_to_back(stack, node);
}

void    ra(t_stack *a) {rotate(a); }

void    rb(t_stack *b) {rotate(b); }

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
