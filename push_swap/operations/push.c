/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:23:52 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/18 13:26:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(t_stack *from, t_stack *to)
{
    t_node  *node;

    if (!from || !from->head)
        return ;
    node = pop_node_front(from);
    add_to_front(to, node);
}

void    pa(t_stack *a, t_stack *b)
{
    push(b, a);
    printf("pa\n");
}

void    pb(t_stack *a, t_stack *b)
{
    push(a, b);
    printf("pb\n");
}
