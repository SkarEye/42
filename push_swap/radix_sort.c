/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:51:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/11 17:34:00 by macarnie         ###   ########.fr       */
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

static void    assign_index(t_stack *stack)
{
    t_node  *node;
    int     *int_tab;
    size_t  i;

    if (!stack || stack->size == 0)
        return ;
    int_tab = create_int_tab_from_stack(stack);
    if (!int_tab)
        return ;
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

void    print_stacks(t_stack *a, t_stack *b)
{
    t_node  *na = a ? a->head : NULL;
    t_node  *nb = b ? b->head : NULL;

    printf("   A\t\tB\n");
    printf("  ---\t\t---\n");
    while (na || nb)
    {
        if (na)
        {
            printf("%5d", na->value);
            na = na->next;
        }
        else
            printf("     ");
        printf("\t");
        if (nb)
        {
            printf("%5d", nb->value);
            nb = nb->next;
        }
        printf("\n");
    }
    printf("  ---\t\t---\n\n");
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
            static int step = 0;
            printf("Step %d:\n", ++step);
            print_stacks(a, b);
            usleep(100000);
            if ((a->head->index >> i) & 1)
                ra(a);
            else
                pa(a, b);
            printf("j = %zu\n", j);
            print_stacks(a, b);
            j--;
        }

        while (b->size > 0)
            pb(a, b);
        i++;
    }
}
