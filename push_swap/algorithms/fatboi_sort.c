/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatboi_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:55:38 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/18 11:31:33 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void    fb_push(t_stack *a, t_stack *b, size_t index)
{
    size_t  chunk;
    size_t  lower_bound;
    size_t  i;

    if (index > FATBOI_CHUNK)
    {
        lower_bound = index - FATBOI_CHUNK;
        chunk = FATBOI_CHUNK;
    }
    else
    {
        lower_bound = 0;
        chunk = index + 1;
    }
    i = 0;
    while (i < chunk)
    {
        print_stacks(a, b);
        printf("index : %zu, chunk size : %zu, lower bound : %zu\n", index, chunk, lower_bound);
        usleep(1000000);
        if (a->head->index < index && a->head->index >= lower_bound)
        {
            pa(a, b);
            i++;
        }
        else
            ra(a);
    }
}

static void fb_push_back(t_stack *a, t_stack *b, size_t *index)
{
    static int steps;

    while (b->size > 0)
    {
        steps = count_min_steps(b, *index);
        if (steps > 0)
        get_to_index(b, steps, rb, rrb);
        pb(a, b);
        (*index)--;
    }
}

void	fatboi_sort(t_stack *a, t_stack *b)
{
    size_t	index;

    if (!a || !b || a->size < 2 ||  FATBOI_CHUNK < 1)
        return ;
    assign_index(a);
    index = a->size - 1;
    while (index)
    {
        fb_push(a, b, index);
        get_to_index(a, count_min_steps(a, index + 1), ra, rra);
        fb_push_back(a, b, &index);
    }
    rra(a);
}
