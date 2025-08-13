/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:27:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/11 17:25:21 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !stack->head || !stack->head->next)
        return ;
    first = pop_node_front(stack);
    second = pop_node_front(stack);
    add_to_front(stack, first);
    add_to_front(stack, second);
}

void    sa(t_stack *a)
{
    swap(a);
    printf("sa\n");
}

void    sb(t_stack *b)
{
    swap(b);
    printf("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}
