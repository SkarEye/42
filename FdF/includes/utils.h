/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:23:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/05 14:41:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "structures.h"

int	ft_atoi(const char *str);
unsigned int	ft_htoui(const char *str);
size_t	ft_itoa(int n);
size_t	ft_sitoa(char *dst, int n);
void	*ft_bzero(void *s, size_t n);
size_t	ft_countwords(char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_free_strtab(char **strtab);
char	*ft_join(const char *first, const char *last, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	get_next_line(int fd, t_fdf *fdf);

size_t	pos(size_t x, size_t z, t_fdf *fdf);
void	set_map(const char *filename, t_fdf *fdf);

#endif