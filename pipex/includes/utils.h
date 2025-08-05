/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:21:44 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:58:25 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>

size_t  ft_strlen(const char *str);

char	*ft_itoa(int n);

char	*ft_join(const char *first, const char *last, char c);

void	free_split(char **split);
char	**ft_split(const char *str, char c);

#endif