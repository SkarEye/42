/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:14:36 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/26 16:58:49 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stddef.h>

typedef unsigned int		t_uint;
typedef long long			t_ll;
typedef pthread_mutex_t		t_mutex;
typedef pthread_t			t_thread;

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

size_t	ft_sitoa(char *buf, int n);
size_t	ft_sutoa(char *buf, unsigned int n);

int		ft_atou_safe(const char *str, t_uint *out);

#endif
