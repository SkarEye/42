/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:51:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/04 20:28:14 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  get_max_int(t_stack *stack)
{
    t_node  *node;
    int     max;

    if (!stack || !stack->head)
        return (0);
    max = stack->head->value;
    node = stack->head->next;
    while (node)
    {
        if (node->value > max)
            max = node->value;
        node = node->next;
    }
    return (max);
}

static char get_max_bits(int max)
{
    char    bits;

    bits = 0;
    while (max)
    {
        max >>= 1;
        bits++;
    }
    return (bits);
}

void    assign_index(t_stack *stack)
{
    t_node  *node;
    int     *int_tab;
    size_t  i;

    if (!stack || stack->size == 0)
        return ;
    int_tab = malloc(sizeof(int) * stack->size);
    if (!int_tab)
        return ;
    node = stack->head;
    i = 0;
    while (node)
    {
        int_tab[i++] = node->value;
        node = node->next;
    }
    sort_int_tab(int_tab, stack->size);
    node = stack->head;
    while (node)
    {
        i = 0;
        while (int_tab[i] != node->value)
            i++;
        node->index = i;
        node = node->next;
    }
    free(int_tab);
}


void    radix_sort();