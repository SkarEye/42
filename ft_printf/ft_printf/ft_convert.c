/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:42:55 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/23 15:21:04 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert(t_format *f, char *str, size_t maxlen, va_list args)
{
	if (f->specifier == 'c')
		return (ft_convert_char(f, str, maxlen, args));
	else if (f->specifier == 's')
		return (ft_convert_string(f, str, maxlen, args));
	else if (f->specifier == '%')
		return (ft_convert_percent(str, maxlen));
	else if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_convert_int(f, str, maxlen, args));
	else if (f->specifier == 'u')
		return (ft_convert_uint(f, str, maxlen, args));
	else if (f->specifier == 'x' || f->specifier == 'X')
		return (ft_convert_hex(f, str, maxlen, args));
	else if (f->specifier == 'p')
		return (ft_convert_ptr(f, str, maxlen, args));
	return (0);
}

size_t	ft_convert_char(t_format *f, char *str, size_t maxlen, va_list args)
{
	char	c;
	size_t	width;

	c = (char)va_arg(args, int);
	width = ft_max(1, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (f->flags & FLAG_MINUS)
		str[0] = c;
	else
		str[width - 1] = c;
	return (width);
}

size_t	ft_convert_null(t_format *f, char *str, size_t maxlen)
{
	if (f->flags & FLAG_PRECISION && f->precision < 6)
	{
		if (f->width > maxlen)
			return (f->width);
		ft_memset(str, ' ', f->width);
		return (f->width);
	}
	f->width = ft_max(6, f->width);
	if (f->width > maxlen)
		return (f->width);
	ft_memset(str, ' ', f->width);
	if (f->flags & FLAG_MINUS)
		ft_memmove(str, NULL_STR, 6);
	else
		ft_memmove(str + f->width - 6, NULL_STR, 6);
	return (f->width);
}

size_t	ft_convert_string(t_format *f, char *str, size_t maxlen, va_list args)
{
	char	*s;
	size_t	len;
	size_t	width;

	s = va_arg(args, char *);
	if (!s)
		return (ft_convert_null(f, str, maxlen));
	len = ft_strlen(s);
	if (f->flags & FLAG_PRECISION && f->precision < len)
		len = f->precision;
	width = ft_max(len, f->width);
	if (width > maxlen)
		return (width);
	ft_memset(str, ' ', width);
	if (f->flags & FLAG_MINUS)
		ft_memmove(str, s, len);
	else
		ft_memmove(str + width - len, s, len);
	return (width);
}

size_t	ft_convert_percent(char *str, size_t maxlen)
{
	if (maxlen < 1)
		return (1);
	str[0] = '%';
	return (1);
}
