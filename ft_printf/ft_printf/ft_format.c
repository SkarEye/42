/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:41:06 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/13 12:04:49 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_set_flags(t_format *format, const char *str, size_t *i)
{
    while (str[*i] && ft_strchr(FLAGS, str[*i]))
    {
        if (str[*i] == '-')
            format->flags |= FLAG_MINUS; // Left justify
        else if (str[*i] == '+')
            format->flags |= FLAG_PLUS; // Force sign
        else if (str[*i] == '0')
            format->flags |= FLAG_ZERO; // Zero padding
        else if (str[*i] == ' ')
            format->flags |= FLAG_SPACE; // Space for positive numbers
        else if (str[*i] == '#')
            format->flags |= FLAG_HASH; // Alternate form
        (*i)++;
    }
}
void    ft_set_width(t_format *format, const char *str, size_t *i, va_list args)
{
    if (str[*i] && str[*i] == '*')
    {
        format->width = va_arg(args, int);
        if (format->width < 0)
        {
            format->flags |= FLAG_MINUS;
            format->width = -format->width;
        }
        (*i)++;
    }
    else
    {
        while (str[*i] && ft_isdigit(str[*i]))
        {
            format->width = format->width * 10 + (str[*i] - '0');
            (*i)++;
        }
    }
}


void    ft_set_precision(t_format *format, const char *str, size_t *i, va_list args)
{
    if (str[*i] && str[*i] == '.')
    {
        (*i)++;
        format->precision = 0;
        if (str[*i] && str[*i] == '*')
        {
            format->precision = va_arg(args, int);
            (*i)++;
        }
        else
        {
            while (str[*i] && ft_isdigit(str[*i]))
            {
                format->precision = format->precision * 10 + (str[*i] - '0');
                (*i)++;
            }
        }
    }
}

void ft_set_specifier(t_format *format, const char *str, size_t *i)
{
    if (str[*i] && ft_strchr(SPECS, str[*i]))
    {
        format->specifier = str[*i];
        (*i)++;
    }
    else
        format->specifier = 0;
}

void    ft_set_format(t_format *format, const char *str, size_t *i, va_list args)
{
    (*i)++; // Skip the '%'
    format->flags = 0; // Reset flags
    format->width = 0; // Reset width
    format->precision = -1; // Reset precision
    format->specifier = 0; // Reset specifier
    ft_set_flags(format, str, i); // Set flags
    ft_set_width(format, str, i, args); // Set width
    ft_set_precision(format, str, i, args); // Set precision
    ft_set_specifier(format, str, i); // Set specifier
    if (format->specifier == 0)
        format->specifier = '%'; // Default to '%' if no specifier found
}
