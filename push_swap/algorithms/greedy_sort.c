/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 05:54:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/18 14:05:00 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    greedy_sort(t_stack *a, t_stack *b)
{
    size_t index;

    if (!a || !b || a->size < 2)
        return ;
    assign_index(a);
    index = 0;
    while (a->size > 0)
    {
        get_to_index(a, count_min_steps(a, index), ra, rra);
        pb(a, b);
        index++;
    }

    while (b->size > 0)
        pa(a, b);
}
