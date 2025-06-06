/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:52:00 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/04 19:40:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next_node;

    if (!stack)
        return ;
    current = stack->head;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    free(stack);
}

t_stack *create_stack(int *tab, size_t size)
{
    t_stack *stack;
    t_node *new_node;
    size_t i;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = size;
    i = 0;
    while (i < size)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
           return (free_stack(stack), NULL);
        new_node->value = tab[i];
        new_node->index = i++;
        add_to_back(stack, new_node);
    }
    return (stack);
}
