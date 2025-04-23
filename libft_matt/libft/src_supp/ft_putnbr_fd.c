/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:57:13 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/23 18:20:38 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-(n / 10), fd);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	n %= 10;
	if (n < 0)
		n = -n;
	c = n + '0';
	write(fd, &c, 1);
}
