/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:05:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 13:23:38 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stddef.h>

# include "structures.h"

t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
t_stack	*create_stack_from_args(char **str_tab, size_t size);

#endif