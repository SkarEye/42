/* ************************************************************************** */ 
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:51:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/23 14:09:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t get_max_bits(int size)
{
    size_t    bits;

    bits = 0;
    while (size)
    {
        size >>= 1;
        bits++;
    }
    return (bits);
}

void    radix_sort(t_stack *a, t_stack *b)
{
    size_t  max_bits;
    size_t  i;
    size_t  j;

    if (!a || !b || a->size < 2)
        return ;
    assign_index(a);
    max_bits = get_max_bits(a->size - 1);
    i = 0;
    while (i < max_bits)
    {
        j = a->size;
        while (j > 0)
        {
            if ((a->head->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j--;
        }
        while (b->size > 0)
            pa(a, b);
        i++;
    }
}
