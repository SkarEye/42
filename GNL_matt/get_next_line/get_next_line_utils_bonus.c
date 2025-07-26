/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:42:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/23 19:14:44 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = (dst > src) * (n - 1);
	while (n--)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i += (dst < src) - (dst > src);
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1 && s1[len_s1])
		len_s1++;
	while (s2 && s2[len_s2])
		len_s2++;
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}

t_fd_list	*get_fd_node(t_fd_list **fd_list, int fd)
{
	t_fd_list	*prev;
	t_fd_list	*node;

	node = *fd_list;
	prev = NULL;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->stash = NULL;
	node->next = NULL;
	if (prev)
		prev->next = node;
	else
		*fd_list = node;
	return (node);
}

void	destroy_fd_node(t_fd_list **fd_list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*prev;

	if (!fd_list || !*fd_list)
		return ;
	current = *fd_list;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_list = current->next;
			free(current->stash);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
