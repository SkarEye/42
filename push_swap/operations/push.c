/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:23:52 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/03 19:27:15 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack *from, t_stack *to)
{
    t_node  *node;

    if (!from || !from->head)
        return ;
    node = pop_node_front(from);
    add_to_front(to, node);
}

void    pa(t_stack *a, t_stack *b) {push(a, b); }

void    pb(t_stack *a, t_stack *b) {push(b, a); }
