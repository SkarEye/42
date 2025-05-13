/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:58:08 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/13 13:27:29 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FLAGS " -+0#"
# define SPECS "cspdiouxX%"
# define HEX "0123456789abcdef"
# define FLAG_MINUS (1 << 0)
# define FLAG_PLUS (1 << 1)
# define FLAG_ZERO (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_HASH (1 << 4)

typedef struct s_format
{
	unsigned char	flags; // bitfield for flags 00011001
	int				width;
	int				precision;
	char			specifier;
}	t_format;

int	ft_snprintf(char *str, size_t maxlen, const char *format, ...);
int	ft_sprintf(char *str, const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);

int	ft_vsnprintf(char *str, size_t maxlen, const char *format, va_list args);
int	ft_vsprintf(char *str, const char *format, va_list args);
int	ft_vdprintf(int fd, const char *format, va_list args);
int	ft_vprintf(const char *format, va_list args);

int	ft_set_format(t_format *format, const char *str, int *i, va_list args);

size_t	ft_int_countdigits(int n);
size_t	ft_uint_countdigits(unsigned int n);
size_t	ft_hex_countdigits(unsigned int n);

#endif