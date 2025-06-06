/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:28:59 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/23 15:22:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_int(t_format *f, char *str, size_t maxlen, va_list args)
{
	int		n;
	size_t	len;
	size_t	width;

	n = va_arg(args, int);
	len = ft_int_countlen(f, n);
	width = ft_max(len, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (len == 0)
		return (width);
	if (f->flags & FLAG_MINUS)
		ft_sitoa(str, f, n);
	else
		ft_sitoa(str + width - len, f, n);
	return (width);
}

size_t	ft_convert_uint(t_format *f, char *str, size_t maxlen, va_list args)
{
	unsigned int	n;
	size_t			len;
	size_t			width;

	n = va_arg(args, unsigned int);
	len = ft_uint_countlen(f, n);
	width = ft_max(len, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (len == 0)
		return (width);
	if (f->flags & FLAG_MINUS)
		ft_sutoa(str, f, n);
	else
		ft_sutoa(str + width - len, f, n);
	return (width);
}

size_t	ft_convert_hex(t_format *f, char *str, size_t maxlen, va_list args)
{
	unsigned int	n;
	size_t			len;
	size_t			width;

	n = va_arg(args, unsigned int);
	len = ft_hex_countlen(f, n);
	width = ft_max(len, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (len == 0)
		return (width);
	if (f->flags & FLAG_MINUS)
		ft_sutoh(str, f, n);
	else
		ft_sutoh(str + width - len, f, n);
	return (width);
}

size_t	ft_convert_nil(t_format *f, char *str, size_t maxlen)
{
	if (f->flags & FLAG_PRECISION && f->precision < 6)
	{
		if (f->width > maxlen)
			return (f->width);
		ft_memset(str, ' ', f->width);
		return (f->width);
	}
	f->width = ft_max(5, f->width);
	if (f->width > maxlen)
		return (f->width);
	ft_memset(str, ' ', f->width);
	if (f->flags & FLAG_MINUS)
		ft_memmove(str, NIL_STR, 5);
	else
		ft_memmove(str + f->width - 5, NIL_STR, 5);
	return (f->width);
}

size_t	ft_convert_ptr(t_format *f, char *str, size_t maxlen, va_list args)
{
	unsigned long	n;
	size_t			len;
	size_t			width;

	n = (unsigned long)va_arg(args, void *);
	if (n == 0)
		return (ft_convert_nil(f, str, maxlen));
	len = ft_ptr_countlen(f, n);
	width = ft_max(len, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (f->flags & FLAG_MINUS)
		ft_sultoh(str, f, n);
	else
		ft_sultoh(str + width - len, f, n);
	return (width);
}
