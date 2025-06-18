/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:15:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/06/18 11:26:47 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fatboi_sort(a, b);
	is_sorted(a, 1, 1);
	print_stacks(a, b);
	free_stack(a);
	free_stack(b);
	free(tab);
	return (0);
}
