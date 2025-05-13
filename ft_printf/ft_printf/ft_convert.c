/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:42:55 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/12 16:50:11 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_convert(t_format *f, char *str, int maxlen, va_list args)
{
    switch (f->specifier)
    {
        case 'c':
            return (ft_convert_char(f, str, maxlen, args));
        case 's':
            return (ft_convert_string(f, str, maxlen, args));
        case 'd':
        case 'i':
            return (ft_convert_int(f, str, maxlen, args));
        case 'u':
            return (ft_convert_unsigned(f, str, maxlen, args));
        case 'x':
        case 'X':
        case 'p':
            return (ft_convert_hex(f, str, maxlen, args));
        case '%':
            return (ft_convert_percent(f, str, maxlen));
        default:
            return (0);
    }
}

