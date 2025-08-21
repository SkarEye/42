/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:07:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/21 16:18:22 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_UTILS_H
# define NODE_UTILS_H

# include "structures.h"

void	add_to_front(t_stack *stack, t_node *new_node);
void	add_to_back(t_stack *stack, t_node *new_node);
t_node	*pop_node_front(t_stack *stack);
t_node	*pop_node_back(t_stack *stack);

#endif