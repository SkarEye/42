/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:58:59 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/19 16:39:38 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

#include "structures.h"

void	small_sort(t_stack *a, t_stack *b);

void	radix_sort(t_stack *a, t_stack *b);
void	greedy_sort(t_stack *a, t_stack *b);
void	xtra_greedy_sort(t_stack *a, t_stack *b);
void	fatboi_sort(t_stack *a, t_stack *b);

#endif