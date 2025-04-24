/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:25:58 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/24 14:03:30 by macarnie         ###   ########.fr       */
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


int	ft_printf(const char *format, ...)
{
	va_list	args;
	
	va_start(args, format);
	va_end(args);

	int	i;
	char	*value;

	i = 0;
	while (i++ < 3)
	{
		value = va_arg(args, char *);
		write(1, value, ft_strlen(value));
	}
	return (0);
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