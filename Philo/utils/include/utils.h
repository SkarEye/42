/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:14:36 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/30 14:46:41 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

size_t	ft_sitoa(char *buf, int n);
size_t	ft_sutoa(char *buf, unsigned int n);

int		ft_atou_safe(const char *str, unsigned int *out);

#endif
