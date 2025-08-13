/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:05:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:07:08 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stddef.h>

# include "structures.h"

void	free_stack(t_stack *stack);
t_stack	*create_stack_from_int_tab(int *tab, size_t size);
int		*create_int_tab_from_stack(t_stack *stack);

#endif