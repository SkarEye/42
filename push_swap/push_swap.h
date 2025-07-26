/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:21:29 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/19 14:30:51 by macarnie         ###   ########.fr       */
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

# define FLAG_PA 1
# define FLAG_PB 2
# define FLAG_RA 4
# define FLAG_RB 8
# define FLAG_RRA 16
# define FLAG_RRB 32
# define FLAG_SA 64
# define FLAG_SB 128

typedef struct	s_node
{
	int		value;
	size_t	index;
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

void    print_stacks(t_stack *a, t_stack *b);
void	do_ops(t_stack *a, t_stack *b, unsigned char flags);
void    assign_index(t_stack *stack);
char	is_sorted(t_stack *stack, char dir, char error_msg);
int		count_min_steps(t_stack *a, size_t index);
void	get_to_index(t_stack *a, int steps, 
		void (*r)(t_stack *), void (*rr)(t_stack *));
int		is_index_in_stack(t_stack *stack, size_t index);

void	radix_sort(t_stack *a, t_stack *b);
void	greedy_sort(t_stack *a, t_stack *b);
void	xtra_greedy_sort(t_stack *a, t_stack *b);
void	fatboi_sort(t_stack *a, t_stack *b);

#endif
