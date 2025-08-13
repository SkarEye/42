/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:39:36 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/13 18:13:04 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // to be rm-ed
#include "structures.h"

# define FLAG_PA 1
# define FLAG_PB 2
# define FLAG_RA 4
# define FLAG_RB 8
# define FLAG_RRA 16
# define FLAG_RRB 32
# define FLAG_SA 64
# define FLAG_SB 128

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(~n + 1));
	return ((unsigned int)n);
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


void    do_ops(t_stack *a, t_stack *b, unsigned char flags)
{
    if (flags & FLAG_PA)
        return (pa(a, b));
    else if (flags & FLAG_PB)
        return (pb(a, b));
    else if (flags & FLAG_RA && flags & FLAG_RB)
        return (rr(a ,b));
    else if (flags & FLAG_RRA && flags & FLAG_RRB)
        return (rrr(a ,b));
    else if (flags & FLAG_SA && flags & FLAG_SB)
        return (ss(a ,b));
    if (flags & FLAG_RA)
        ra(a);
    else if (flags & FLAG_RRA)
        rra(a);
    else if (flags & FLAG_SA)
        sa(a);
    if (flags & FLAG_RB)
        rb(b);
    else if (flags & FLAG_RRB)
        rrb(b);
    else if (flags & FLAG_SB)
        sb(b);
}

void    assign_index(t_stack *stack)
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

char    is_sorted(t_stack *stack, char dir, char print_msg)
{
	t_node *current;

	if (!stack || stack->size < 2)
		return (0);
	current = stack->head;
	while (current && current->next)
	{
		if (current->index + dir != current->next->index)
		{
            if (print_msg)
			    write(1, FAILURE_MSG, sizeof(FAILURE_MSG) - 1);
			return (0);
		}
		current = current->next;
	}
    if (print_msg)
        write(1, SUCCESS_MSG, sizeof(SUCCESS_MSG) - 1);
    return (1);
}

int count_min_steps(t_stack *stack, size_t index)
{
    int steps_forwards;
    int steps_backwards;
    t_node *node;

    steps_forwards = 0;
    node = stack->head;
    while (node && node->index != index)
    {
        steps_forwards++;
        node = node->next;
    }
    steps_backwards = -1;
    node = stack->tail;
    while (node && node->index != index)
    {
        steps_backwards--;
        node = node->prev;
    }
    if (-steps_forwards > steps_backwards)
        return (steps_forwards);
    else
        return (steps_backwards);
}


void    get_to_index(t_stack *stack, int steps,
    void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *))
{
    while (steps > 0)
    {
        rotate(stack);
        steps--;
    }
    while (steps < 0)
    {
        rev_rotate(stack);
        steps++;
    }
}

int is_index_in_stack(t_stack *stack, size_t index)
{
    t_node  *current;
    
    if (!stack || stack->size == 0)
        return (0);
    current = stack->head;
    while (current)
    {
        if (current->index == index)
            return (1);
        current = current->next;
    }
    return (0);
}
