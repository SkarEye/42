/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:00:49 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 18:37:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "operations.h"
#include "utils/stack_utils.h"
#include "checker/get_next_line.h"
#include "utils/error_utils.h"

#include <stdio.h>

static bool	do_instruction(t_stack *a, t_stack *b, const char *instr)
{
	if (!ft_strcmp(instr, PA))
		swap(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (print_error(ERROR), 1);
	a =	create_stack_from_args(argv + 1, argc - 1);
	if (!a)
		return (print_error(ERROR), 1);
	b = init_stack();
	if (!b)
		return (free_stack(a), print_error(ERROR), 1);
	line = get_next_line(stdin);
}
