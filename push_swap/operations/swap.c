/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:27:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/03 19:29:32 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !stack->head || !stack->head->next)
        return ;
    first = pop_node_front(stack);
    second = pop_node_front(stack);
    add_to_front(stack, second);
    add_to_front(stack, first);
}

void    sa(t_stack *a) {swap(a); }

void    sb(t_stack *b) {swap(b); }

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
