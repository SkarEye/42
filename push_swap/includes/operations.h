/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:02:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 18:27:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "structures.h"

# define PA	"pa\n"
# define PB	"pb\n"

# define SA	"sa\n"
# define SB	"sb\n"
# define SS	"ss\n"

#define RA	"ra\n"
#define RB	"rb\n"
#define RR	"rr\n"

#define RRA	"rra\n"
#define RRB	"rrb\n"
#define RRR	"rrr\n"

typedef	enum e_do_op
{
	DO_PA,
	DO_PB,
	DO_SA,
	DO_SB,
	DO_SS,
	DO_RA,
	DO_RB,
	DO_RR,
	DO_RRA,
	DO_RRB,
	DO_RRR,
	STOP
}			t_do_op;

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	do_op(t_stack *a, t_stack *b, t_do_op op);

#endif