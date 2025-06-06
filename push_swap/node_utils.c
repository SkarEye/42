/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:28:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/04 19:41:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   add_to_front(t_stack *stack, t_node *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = stack->head;
    new_node->prev = NULL;
    if (stack->head)
        stack->head->prev = new_node;
    else
        stack->tail = new_node;
    stack->head = new_node;
    stack->size++;
}

void    add_to_back(t_stack *stack, t_node *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = NULL;
    new_node->prev = stack->tail;
    if (!stack->head)
        stack->head = new_node;
    else
        stack->tail->next = new_node;
    stack->tail = new_node;
    stack->size++;
}

t_node  *pop_node_front(t_stack *stack)
{
    t_node *node;

    if (!stack || !stack->head)
        return (NULL);
    node = stack->head;
    stack->head = node->next;
    if (stack->head)
        stack->head->prev = NULL;
    else
        stack->tail = NULL;
    node->next = NULL;
    node->prev = NULL;
    stack->size--;
    return (node);
}

t_node  *pop_node_back(t_stack *stack)
{
    t_node *node;

    if (!stack || !stack->tail)
        return (NULL);
    node = stack->tail;
    stack->tail = node->prev;
    if (stack->tail)
        stack->tail->next = NULL;
    else
        stack->head = NULL;
    node->next = NULL;
    node->prev = NULL;
    stack->size--;
    return (node);
}
