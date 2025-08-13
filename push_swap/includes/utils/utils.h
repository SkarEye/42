/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:10:54 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:11:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "structures.h"

void    print_stacks(t_stack *a, t_stack *b);
void	do_ops(t_stack *a, t_stack *b, unsigned char flags);
void    assign_index(t_stack *stack);
char	is_sorted(t_stack *stack, char dir, char error_msg);
int		count_min_steps(t_stack *a, size_t index);
void	get_to_index(t_stack *a, int steps, 
		void (*r)(t_stack *), void (*rr)(t_stack *));
int		is_index_in_stack(t_stack *stack, size_t index);

#endif