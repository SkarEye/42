/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:20:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/15 17:16:29 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sutoa(char *str, t_format *f, unsigned int n)
{
	size_t	i;

	i = 0;
	if (f->flags & FLAG_SPACE)
		str[i++] = ' ';
	else if (f->flags & FLAG_PLUS)
		str[i++] = '+';
	ft_memset(str + i, '0', f->precision);
	i += ft_max(f->precision, ft_ubase_countdigits(n, 10)) - 1;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
}

void	ft_sitoa(char *str, t_format *f, int n)
{
	size_t			i;
	unsigned int	abs_n;

	if (n < 0)
		abs_n = (unsigned int)(~n + 1);
	else
		abs_n = (unsigned int)n;
	i = 0;
	if (f->flags & FLAG_SPACE && n >= 0)
		str[i++] = ' ';
	else if (f->flags & FLAG_PLUS && n >= 0)
		str[i++] = '+';
	else if (n < 0)
		str[i++] = '-';
	ft_memset(str + i, '0', f->precision);
	i += ft_max(f->precision, ft_ubase_countdigits(abs_n, 10)) - 1;
	if (abs_n == 0)
		str[i] = '0';
	while (abs_n != 0)
	{
		str[i--] = abs_n % 10 + '0';
		abs_n /= 10;
	}
}

void	ft_sutoh(char *str, t_format *f, unsigned int n)
{
	size_t	i;

	i = 0;
	if ((f->flags & FLAG_HASH) || (f->specifier == 'p'))
	{
		str[i++] = '0';
		if (f->specifier == 'X')
			str[i++] = 'X';
		else
			str[i++] = 'x';
	}
	ft_memset(str + i, '0', f->precision);
	i += ft_max(f->precision, ft_ubase_countdigits(n, 16)) - 1;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		if (f->specifier == 'X')
			str[i--] = HEX_UP[n % 16];
		else
			str[i--] = HEX[n % 16];
		n /= 16;
	}
}

void	ft_sultoh(char *str, t_format *f, unsigned long n)
{
	size_t	i;

	i = 0;
	str[i++] = '0';
	str[i++] = 'x';
	ft_memset(str + i, '0', f->precision);
	i += ft_max(f->precision, ft_ulbase_countdigits(n, 16)) - 1;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i--] = HEX[n % 16];
		n /= 16;
	}
}
