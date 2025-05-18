/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:14:33 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/16 15:08:24 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_terminate(char *str, size_t len, size_t maxlen)
{
	if (maxlen > 0)
	{
		if (len < maxlen)
			str[len] = '\0';
		else
			str[maxlen - 1] = '\0';
	}
}

int	ft_vsnprintf(char *str, size_t maxlen, const char *format, va_list args)
{
	size_t		i;
	size_t		len;
	t_format	f;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_set_format(&f, format, &i, &args);
			if (len < maxlen)
				len += ft_convert(&f, str + len, maxlen - len, &args);
			else 
				len += ft_convert(&f, NULL, 0, &args);
		}
		else
		{
			if (len < maxlen)
				str[len] = format[i];
			len++;
			i++;
		}
	}
	ft_terminate(str + len, len, maxlen);
	return ((int)len);
}

int	ft_vsprintf(char *str, const char *format, va_list args)
{
	return (ft_vsnprintf(str, (size_t) - 1, format, args));
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	char	s_buffer[1];
	char	*h_buffer;
	va_list	args_copy;
	int		len;

	if (format == NULL)
		return (-1);
	va_copy(args_copy, args);
	len = ft_vsnprintf(NULL, 0, format, args_copy);
	va_end(args_copy);
	if (len < (int)(sizeof(s_buffer)))
	{
		ft_vsnprintf(s_buffer, len + 1, format, args);
		return (write(fd, s_buffer, len));
	}
	else
	{
		h_buffer = malloc(sizeof(char) * (len + 1));
		if (!h_buffer)
			return (-1);
		va_copy(args_copy, args);
		ft_vsnprintf(h_buffer, len + 1, format, args_copy);
		va_end(args_copy);
		write(fd, h_buffer, len);
		free(h_buffer);
		return (len);
	}
}

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(1, format, args));
}
