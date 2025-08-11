/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:21:44 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/11 19:51:53 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>

void	*ft_bzero(void *s, size_t n);

void	ft_free_strtab(char **strtab);

int		ft_is_whitespace(char c);

char	*ft_itoa(int n);
size_t	ft_sitoa(char *dst, int n);

char	*ft_join(const char *first, const char *last, char c);

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	**ft_split(const char *str, char c);

char	*ft_strchr(const char *s, int c);

size_t	ft_strcmp(const char *s1, const char *s2);

char	*ft_strdup(const char *src);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_strtabndup(char **srctab, size_t size);

#endif