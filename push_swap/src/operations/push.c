/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:23:52 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 18:25:20 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structures.h"
#include "operations.h"
#include "utils/node_utils.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from || !from->head)
		return ;
	node = pop_node_front(from);
	add_to_front(to, node);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, PA, 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, PB, 3);
}
