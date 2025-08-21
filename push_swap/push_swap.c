/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:15:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 18:11:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"
#include "algorithms.h"
#include "utils/error_utils.h"
#include "utils/stack_utils.h"


#include <stdio.h>
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
			printf("%5d, ", na->value);
			printf("%5zu", na->index);
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

static void	free_push_swap(t_push_swap *push_swap)
{
	if (!push_swap)
		return ;
	if (push_swap->a)
		free_stack(push_swap->a);
	if (push_swap->b)
		free_stack(push_swap->b);
	free(push_swap);
	push_swap = NULL;
}

static t_push_swap	*init_push_swap(char **str_tab, size_t size)
{
	t_push_swap	*push_swap;

	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->a = NULL;
	push_swap->b = NULL;
	push_swap->a = create_stack_from_args(str_tab, size);
	if (!push_swap->a)
		return (free_push_swap(push_swap), NULL);
	push_swap->b = (t_stack *)malloc(sizeof(t_stack));
	push_swap->b = init_stack();
	if (!push_swap->b)
		return (free_push_swap(push_swap), NULL);
	return (push_swap);
}

static bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (false);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value >= current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

int main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc < 2)
		return (print_error(ERROR), 1);
	push_swap = init_push_swap(argv + 1, argc - 1);
	if (!push_swap)
		return (print_error(ERROR), 1);
	if (is_sorted(push_swap->a))
		return (0);
	print_stacks(push_swap->a, push_swap->b);
	if (push_swap->a->size <= 5)
		small_sort(push_swap->a, push_swap->b);
	else
		radix_sort(push_swap->a, push_swap->b);
	print_stacks(push_swap->a, push_swap->b);
	return (free_push_swap(push_swap), 0);
}
