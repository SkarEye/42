/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:41:06 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/15 16:15:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flags(t_format *f, const char *str, size_t *i)
{
	while (str[*i] && ft_strchr(FLAGS, str[*i]))
	{
		if (str[*i] == '-')
			f->flags |= FLAG_MINUS;
		else if (str[*i] == '+')
			f->flags |= FLAG_PLUS;
		else if (str[*i] == '0')
			f->flags |= FLAG_ZERO;
		else if (str[*i] == ' ')
			f->flags |= FLAG_SPACE;
		else if (str[*i] == '#')
			f->flags |= FLAG_HASH;
		(*i)++;
	}
}

void	ft_set_width(t_format *f, const char *str, size_t *i, va_list *args)
{
	if (str[*i] && str[*i] == '*')
	{
		f->width = va_arg(*args, int);
		if (f->width < 0)
		{
			f->flags |= FLAG_MINUS;
			f->width = -f->width;
		}
		(*i)++;
	}
	else
	{
		while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
		{
			f->width = f->width * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
}

void	ft_set_precision(t_format *f, const char *str, size_t *i, va_list *args)
{
	if (str[*i] && str[*i] == '.')
	{
		(*i)++;
		f->flags |= FLAG_PRECISION;
		if (str[*i] && str[*i] == '*')
		{
			f->precision = va_arg(*args, int);
			(*i)++;
		}
		else
		{
			while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
			{
				f->precision = f->precision * 10 + (str[*i] - '0');
				(*i)++;
			}
		}
	}
}

void	ft_set_specifier(t_format *f, const char *str, size_t *i)
{
	if (str[*i] && ft_strchr(SPECS, str[*i]))
	{
		f->specifier = str[*i];
		(*i)++;
	}
	else
		f->specifier = 0;
}

void	ft_set_format(t_format *f, const char *str, size_t *i, va_list *args)
{
	(*i)++;
	f->flags = 0;
	f->width = 0;
	f->precision = 0;
	f->specifier = 0;
	ft_set_flags(f, str, i);
	ft_set_width(f, str, i, args);
	ft_set_precision(f, str, i, args);
	ft_set_specifier(f, str, i);
	if (f->specifier == 0)
		f->specifier = '%';
}
