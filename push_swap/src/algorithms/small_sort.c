/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:24:53 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 17:04:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "structures.h"
#include "operations.h"
#include "utils/algo_helper.h"

static void	three_sort(t_stack *a, t_stack *b, size_t offset)
{
	const t_do_op	ops[][3] = {
	{DO_RRA, DO_SA, STOP},
	{DO_RRA, STOP, STOP},
	{DO_SA, STOP, STOP},
	{DO_SA, DO_RRA, STOP},
	{DO_RA, STOP, STOP}
	};

	if (a->size != 3)
		return ;
	if (a->head->index == offset && a->tail->index == offset + 1)
		print_ops(a, b, ops[0]);
	else if (a->head->index == offset + 1 && a->tail->index == offset)
		print_ops(a, b, ops[1]);
	else if (a->head->index == offset + 1 && a->tail->index == offset + 2)
		print_ops(a, b, ops[2]);
	else if (a->head->index == offset + 2 && a->tail->index == offset)
		print_ops(a, b, ops[3]);
	else if (a->head->index == offset + 2 && a->tail->index == offset + 1)
		print_ops(a, b, ops[4]);
	else
		return ;
}

void	small_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if (!a || !b || a->size < 2)
		return ;
	if (a->size == 2 && a->head->index == 1 && a->tail->index == 0)
		sa(a);
	else if (a->size == 3)
		three_sort(a, b, 0);
	else
	{
		i = 0;
		while (a->size > 3)
		{
			get_to_index(a, count_min_steps(a, i++), ra, rra);
			pb(a, b);
		}
		three_sort(a, b, i);
		while (i-- > 0)
			pa(a, b);
	}
}
