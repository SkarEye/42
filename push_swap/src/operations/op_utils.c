/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:53:56 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 18:34:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "operations.h"

void	do_op(t_stack *a, t_stack *b, t_do_op op)
{
	if (op == DO_PA)
		pa(a, b);
	else if (op == DO_PB)
		pb(a, b);
	else if (op == DO_RR)
		rr(a ,b);
	else if (op == DO_RRR)
		rrr(a ,b);
	else if (op == DO_SS)
		ss(a ,b);
	else if (op == DO_RA)
		ra(a);
	else if (op == DO_RRA)
		rra(a);
	else if (op == DO_SA)
		sa(a);
	else if (op == DO_RB)
		rb(b);
	else if (op == DO_RRB)
		rrb(b);
	else if (op == DO_SB)
		sb(b);
}
