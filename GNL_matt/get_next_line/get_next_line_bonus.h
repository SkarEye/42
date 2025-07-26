/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:30:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/23 19:15:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*stash;
	struct s_fd_list	*next;
}	t_fd_list;

char		*get_next_line(int fd);

char		*ft_strchr(const char *s, int c);
void		*ft_memmove(void *dst, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);

t_fd_list	*get_fd_node(t_fd_list **fd_list, int fd);
void		destroy_fd_node(t_fd_list **fd_list, int fd);

#endif