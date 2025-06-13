/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:31:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/11 17:24:51 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rev_rotate(t_stack *stack)
{
    t_node *node;

    if (!stack || !stack->tail || !stack->tail->prev)
        return ;
    node = pop_node_back(stack);
    add_to_front(stack, node);
}

void    rra(t_stack *a)
{
    rev_rotate(a);
    printf("rra\n");
}

void    rrb(t_stack *b)
{
    rev_rotate(b);
    printf("rrb\n");
}

void    rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a);
    rev_rotate(b);
    printf("rrr\n");
}
