/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:25:58 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/12 12:30:02 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar('%');
			else if (format[i] == 'c')
				ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				ft_print_itoa(va_arg(args, int));
			else if (format[i] == 'u')
				ft_print_utoa(va_arg(args, unsigned int));
			else if (format[i] == 'p' || format[i] == 'x')
				ft_print_itoh(va_arg(args, unsigned int), 'a');
			else if (format[i] == 'p' || format[i] == 'X')
				ft_print_itoh(va_arg(args, unsigned int), 'A');
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (i);
}
