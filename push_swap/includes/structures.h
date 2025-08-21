/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:01:43 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/16 20:04:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

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

typedef struct	s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}				t_push_swap;


#endif