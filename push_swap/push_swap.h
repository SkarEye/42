/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:21:29 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/04 20:00:18 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
    int     value;
    size_t  index;
    t_node *prev;
    t_node *next;
}           t_node;

typedef struct s_stack
{
    t_node *head;
    t_node *tail;
    size_t size;
}           t_stack;

void    add_to_front(t_stack *stack, t_node *new_node);
void    add_to_back(t_stack *stack, t_node *new_node);
t_node  *pop_node_front(t_stack *stack);
t_node  *pop_node_back(t_stack *stack);

t_stack *create_stack(int *tab, size_t size);
void    free_stack(t_stack *stack);

int     ft_atoi(const char *str);
int     *create_unique_int_tab(char **str_tab, size_t size);
void    sort_int_tab(int *tab, size_t size);

void    push(t_stack *from, t_stack *to);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

void    swap(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);

void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);

void    rev_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif