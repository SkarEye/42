/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:21:29 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/11 17:01:02 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H	

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include <stdio.h>

# define ERROR_MSG "Error\n"
# define SUCCESS_MSG "OK\n"
# define FAILURE_MSG "KO\n"

typedef struct	s_node
{
	int		value;
	ssize_t	index;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}				t_stack;

void	add_to_front(t_stack *stack, t_node *new_node);
void	add_to_back(t_stack *stack, t_node *new_node);
t_node	*pop_node_front(t_stack *stack);
t_node	*pop_node_back(t_stack *stack);

void	free_stack(t_stack *stack);
t_stack	*create_stack_from_int_tab(int *tab, size_t size);
int		*create_int_tab_from_stack(t_stack *stack);

int		*create_unique_int_tab(char **str_tab, size_t size);
void	sort_int_tab(int *tab, size_t size);

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

void	radix_sort(t_stack *a, t_stack *b);

#endif
