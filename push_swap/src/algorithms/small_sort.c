/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:24:53 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 18:35:01 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "structures.h"
#include "operations.h"
#include "algo_helper.h"

#define SOL_021	(t_do_op[]){DO_RRA, DO_SA, STOP}
#define SOL_120	(t_do_op[]){DO_RRA, STOP}
#define SOL_102	(t_do_op[]){DO_SA, STOP}
#define SOL_210	(t_do_op[]){DO_SA, DO_RRA, STOP}
#define SOL_201	(t_do_op[]){DO_RA, STOP}

static void	three_sort(t_stack *a, t_stack *b, size_t offset)
{
	t_do_op	*ops;
	size_t	i;
	
	if (a->size != 3)
		return ;
	if (a->head->index == offset && a->tail->index == offset + 1)
		ops = SOL_021;
	else if (a->head->index == offset + 1 && a->tail->index == offset)
		ops = SOL_120;
	else if (a->head->index == offset + 1 && a->tail->index == offset + 2)
		ops = SOL_102;
	else if (a->head->index == offset + 2 && a->tail->index == offset)
		ops = SOL_210;
	else if (a->head->index == offset + 2 && a->tail->index == offset + 1)
		ops = SOL_201;
	else
		return ;
	i = 0;
	while (ops[i] != STOP)
		do_op(a, b, ops[i++]);
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
