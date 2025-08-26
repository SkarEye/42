/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:24:53 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 14:28:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "structures.h"
#include "operations.h"
#include "utils/algo_helper.h"

void	small_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if (!a || !b || a->size < 2)
		return ;
	if (a->size == 2 && a->head->index == 1 && a->tail->index == 0)
		sa(a);
	else if (a->size == 3)
		three_sort(a, sa, ra, rra);
	else
	{
		i = 0;
		while (a->size > 3)
		{
			get_to_index(a, count_min_steps(a, i++), ra, rra);
			pb(a, b);
		}
		three_sort(a, sa, ra, rra);
		while (i-- > 0)
			pa(a, b);
	}
}
