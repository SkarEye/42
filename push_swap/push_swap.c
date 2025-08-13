/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:15:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:43:59 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "structures.h"
#include "error_utils.h"

int main(int argc, char **argv)
{
	int *tab;
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	tab = create_unique_int_tab(argv + 1, argc - 1);
	if (!tab)
		return (print_error(ERROR), 1);
	a = create_stack_from_int_tab(tab, argc - 1);
	if (!a)
		return (free(tab), print_error(ERROR), 1);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		return (free(tab), free_stack(a), print_error(ERROR), 1);
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	free(tab);
	return (0);
}
