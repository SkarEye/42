/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:52:00 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/25 15:16:07 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "structures.h"
#include "utils/node_utils.h"
#include "utils/int_tab_utils.h"

static bool	assign_index(t_stack *stack, int *tab, size_t size)
{
	t_node	*node;
	size_t	i;

	if (!stack || !tab || size == 0 || stack->size != size)
		return (false);
	sort_int_tab(tab, size);
	node = stack->head;
	while (node)
	{
		i = 0;
		while (i < size && tab[i] != node->value)
			i++;
		if (i == size)
			return (false);
		node->index = i;
		node = node->next;
	}
	return (true);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

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
	stack = NULL;
}

t_stack	*create_stack_from_args(char **str_tab, size_t size)
{
	t_stack	*stack;
	int		*tab;
	t_node	*new_node;
	size_t	i;

	if (!str_tab || size == 0)
		return (NULL);
	tab = create_unique_int_tab(str_tab, size);
	if (!tab)
		return (NULL);
	stack = init_stack();
	if (!stack)
		return (free(tab), NULL);
	i = 0;
	while (i < size)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (free(tab), free_stack(stack), NULL);
		new_node->value = tab[i++];
		add_to_back(stack, new_node);
	}
	assign_index(stack, tab, size);
	return (free(tab), stack);
}
