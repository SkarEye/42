/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:13:24 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/23 15:44:13 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uint_countlen(t_format *f, unsigned int n)
{
	size_t	len;
	size_t	digits;

	if (f->flags & FLAG_PRECISION && f->precision == 0 && n == 0)
		return (0);
	len = 0;
	digits = ft_ubase_countdigits(n, 10);
	if (f->flags & (FLAG_PLUS | FLAG_SPACE))
		len++;
	if (f->flags & FLAG_PRECISION && f->precision > digits)
		len += f->precision;
	else if (f->flags & FLAG_ZERO
		&& !(f->flags & (FLAG_MINUS | FLAG_PRECISION)) && f->width > digits)
		len = f->width;
	else
		len += digits;
	return (len);
}

size_t	ft_int_countlen(t_format *f, int n)
{
	size_t	len;
	size_t	digits;

	if (f->flags & FLAG_PRECISION && f->precision == 0 && n == 0)
		return (0);
	len = 0;
	if (n < 0)
		digits = ft_ubase_countdigits((unsigned int)(~n + 1), 10);
	else
		digits = ft_ubase_countdigits((unsigned int)n, 10);
	if (n < 0 || (n >= 0 && (f->flags & (FLAG_PLUS | FLAG_SPACE))))
		len++;
	if (f->flags & FLAG_PRECISION && f->precision > digits)
		len += f->precision;
	else if (f->flags & FLAG_ZERO
		&& !(f->flags & (FLAG_MINUS | FLAG_PRECISION)) && f->width > digits)
		len = f->width;
	else
		len += digits;
	return (len);
}

size_t	ft_hex_countlen(t_format *f, unsigned int n)
{
	size_t	len;
	size_t	digits;

	if (f->flags & FLAG_PRECISION && f->precision == 0 && n == 0)
		return (0);
	len = 0;
	if (f->flags & FLAG_HASH && n > 0)
		len += 2;
	digits = ft_ubase_countdigits(n, 16);
	if (f->flags & FLAG_PRECISION && f->precision > digits)
		len += f->precision;
	else if (f->flags & FLAG_ZERO
		&& !(f->flags & (FLAG_MINUS | FLAG_PRECISION)) && f->width > digits)
		len = f->width;
	else
		len += digits;
	return (len);
}

size_t	ft_ptr_countlen(t_format *f, unsigned long n)
{
	size_t	digits;

	if (f->flags & FLAG_PRECISION && f->precision == 0 && n == 0)
		return (2);
	digits = ft_ulbase_countdigits(n, 16);
	if (f->flags & FLAG_PRECISION && f->precision > digits)
		return (f->precision + 2);
	else
		return (digits + 2);
}
