/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:09:26 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:10:04 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_TAB_UTILS_H
# define INT_TAB_UTILS_H

#include <stddef.h>

int		*create_unique_int_tab(char **str_tab, size_t size);
void	sort_int_tab(int *tab, size_t size);

#endif