/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:00:49 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:52:14 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "operations.h"
#include "utils/stack_utils.h"
#include "error_utils.h"
#include "bonus/get_next_line.h"

#include <stdio.h>

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (argc < 2)
		return (print_error(ERROR), 1);
	a =	create_stack_from_args(argv + 1, argc - 1);
	if (!a)
		return (print_error(ERROR), 1);
	b = init_stack();
	if (!b)
		return (free_stack(a), print_error(ERROR), 1);
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (!do_op(a, b, op))
			return (print_error(ERROR), free(op), free_stacks(a, b), 1);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && b->size == 0)
		return (print_error(SUCCESS), free_stacks(a, b), 0);
	else 
		return (print_error(FAILURE), free_stacks(a, b), 1);
}
