/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:53:56 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 16:32:32 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "structures.h"
#include "operations.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

bool	do_op(t_stack *a, t_stack *b, const char *op)
{
	if (!a || !b || !op)
		return (false);
	if (ft_strcmp(op, PA))
		return (push(b, a), true);
	else if (ft_strcmp(op, PB))
		return (push(a, b), true);
	else if (ft_strcmp(op, SA))
		return (swap(a), true);
	else if (ft_strcmp(op, SB))
		return (swap(b), true);
	else if (ft_strcmp(op, SS))
		return (swap(a), swap(b), true);
	else if (ft_strcmp(op, RA))
		return (rotate(a), true);
	else if (ft_strcmp(op, RB))
		return (rotate(b), true);
	else if (ft_strcmp(op, RR))
		return (rotate(a), rotate(b), true);
	else if (ft_strcmp(op, RRA))
		return (rev_rotate(a), true);
	else if (ft_strcmp(op, RRB))
		return (rev_rotate(b), true);
	else if (ft_strcmp(op, RRR))
		return (rev_rotate(a), rev_rotate(b), true);
	return (false);
}

bool	print_op(t_stack *a, t_stack *b, t_do_op op)
{
	if (!a || !b || !(op >= DO_PA && op < STOP))
		return (false);
	if (op == DO_PA)
		return (pa(a, b), true);
	else if (op == DO_PB)
		return (pb(a, b), true);
	else if (op == DO_SA)
		return (sa(a), true);
	else if (op == DO_SB)
		return (sb(b), true);
	else if (op == DO_SS)
		return (ss(a, b), true);
	else if (op == DO_RA)
		return (ra(a), true);
	else if (op == DO_RB)
		return (rb(b), true);
	else if (op == DO_RR)
		return (rr(a, b), true);
	else if (op == DO_RRA)
		return (rra(a), true);
	else if (op == DO_RRB)
		return (rrb(b), true);
	else if (op == DO_RRR)
		return (rrr(a, b), true);
	return (false);
}

bool	print_ops(t_stack *a, t_stack *b, const t_do_op ops[3])
{
	size_t	i;

	if (!a || !b || !ops)
		return (false);
	i = 0;
	while (ops[i] != STOP && i < 3)
	{
		if (!print_op(a, b, ops[i]))
			return (false);
		i++;
	}
	return (true);
}
