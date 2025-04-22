/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:30:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/14 08:08:34 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);

size_t  ft_strlen(const char *s);
void    *ft_memmove(void *dst, const void *src, size_t n);
void    *ft_realloc(void *ptr, size_t old_size, size_t new_size);
#endif