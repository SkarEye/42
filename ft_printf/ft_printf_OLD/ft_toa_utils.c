/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:00:18 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/25 16:36:01 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_print_itoa(int n)
{
	char	str[11];
	size_t	i;

	if (n == 0)
		ft_putchar('0');
	else
	{
		i = 0;
		if (n < 0)
			ft_putchar('-');
		if (n > 0)
			n *= -1;
		while (n != 0)
		{
			str[i++] = '0' - (n % 10);
			n /= 10;
		}
		while (i-- > 0)
			ft_putchar(str[i]);
	}
}

void	ft_print_utoa(unsigned int n)
{
	char	str[11];
	size_t	i;

	if (n == 0)
		ft_putchar('0');
	else
	{
		i = 0;
		while (n != 0)
		{
			str[i++] = '0' + (n % 10);
			n /= 10;
		}
		while (i-- > 0)
			ft_putchar(str[i]);
	}
}

void	ft_print_itoh(unsigned int n, char c)
{
	char	str[8];
	size_t		i;

	if (n == 0)
		ft_putchar('0');
	else
	{
		i = 0;
		while (n != 0)
		{
			if (n % 16 < 10)
				str[i++] = '0' + (n % 16);
			else
				str[i++] = c + (n % 16 - 10);
			n /= 16;
		}
		while (i-- > 0)
			ft_putchar(str[i]);
	}
}