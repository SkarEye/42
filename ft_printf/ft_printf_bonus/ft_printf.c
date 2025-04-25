/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:25:58 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/25 15:37:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

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
			
			else if (format[i] == 'p' || format[i] == )
		}
	}
	return (i);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	ft_printf("This is a test", argv[1]);
	return (0);
}
*/