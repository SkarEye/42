/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra_greedy_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 05:54:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 12:39:46 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "structures.h"
#include "operations.h"
#include "algo_helper.h"

static int    xg_get_min_steps(t_stack *a, size_t min_i, size_t max_i)
{
    int min_steps;
    int max_steps;
    
    min_steps = count_min_steps(a, min_i);
    max_steps = count_min_steps(a, max_i);
    if (ft_abs(min_steps) < ft_abs(max_steps) + 2)
        return (min_steps);
    else
        return (max_steps);
}


static void  xg_push(t_stack *a, t_stack *b)
{
    size_t min_i;
    size_t max_i;

    min_i = 0;
    max_i = a->size - 1;
    while (a->size > 0)
    {
        get_to_index(a, xg_get_min_steps(a, min_i, max_i), ra, rra);
        pb(a, b);
        if (b->head->index == min_i)
            min_i++;
        else
        {
            max_i--;
            rb(b);
        }
    }
}

static void xg_push_back(t_stack *a, t_stack *b)
{
    int steps;

    steps = count_min_steps(b, b->size - 1);
    if (steps > 0)
    {
        while (steps-- > 0)
            rb(b);
    }
    else if (steps < 0)
    {
        while (steps++ < 0)
            rrb(b);
    }
    while (b->size > 0)
        pa(a, b);
}

void    xtra_greedy_sort(t_stack *a, t_stack *b)
{
    if (!a || !b || a->size < 2)
        return ;
    xg_push(a, b);
    xg_push_back(a, b);
}
