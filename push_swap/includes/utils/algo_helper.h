/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:53:20 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:14:41 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_HELPER_H
# define ALGO_HELPER_H

# include <stddef.h>
# include "structures.h"

void			three_sort(t_stack *a, void (*swap)(t_stack *),
					void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *));
int				count_min_steps(t_stack *stack, size_t index);
void			get_to_index(t_stack *stack, int steps,
					void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *));
size_t			find_max_index(t_stack *stack);
size_t			find_min_index(t_stack *stack);

unsigned int	ft_abs(int n);
unsigned int	ft_max(unsigned int a, unsigned int b);
unsigned int	ft_min(unsigned int a, unsigned int b);

#endif