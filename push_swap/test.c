/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:05:10 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/11 17:17:25 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_sorted(t_stack *stack)
{
	t_node *current;

	if (!stack || stack->size < 2)
		return ;
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			write(1, FAILURE_MSG, sizeof(FAILURE_MSG) - 1);
			return ;
		}
		current = current->next;
	}
	write(1, SUCCESS_MSG, sizeof(SUCCESS_MSG) - 1);
}

int main(int argc, char **argv)
{
	int *tab;
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	tab = create_unique_int_tab(argv + 1, argc - 1);
	if (!tab)
		return (write(2, ERROR_MSG, sizeof(ERROR_MSG) - 1), 1);
	a = create_stack_from_int_tab(tab, argc - 1);
	if (!a)
		return (free(tab), write(2, ERROR_MSG, sizeof(ERROR_MSG) - 1), 1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (free_stack(a), write(2, ERROR_MSG, sizeof(ERROR_MSG) - 1), 1);
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	radix_sort(a, b);
	is_sorted(a);
	free_stack(a);
	free_stack(b);
	free(tab);
	return (0);
}
