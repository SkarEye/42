/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:53:20 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 11:56:32 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_HELPER_H
# define ALGO_HELPER_H

# include <stddef.h>
# include "structures.h"

unsigned int	ft_abs(int n);
int				count_min_steps(t_stack *stack, size_t index);
void			get_to_index(t_stack *stack, int steps,
					void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *));
int				is_index_in_stack(t_stack *stack, size_t index);

#endif