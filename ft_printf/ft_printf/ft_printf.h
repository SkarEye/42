/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:58:08 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/22 10:28:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FLAGS " -+0#"
# define SPECS "cspdiuxX%"
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"

# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_ZERO 4
# define FLAG_SPACE 8
# define FLAG_HASH 16
# define FLAG_PRECISION 32

typedef struct s_format
{
	unsigned char	flags;
	size_t			width;
	size_t			precision;
	char			specifier;
}	t_format;

int		ft_snprintf(char *str, size_t maxlen, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

int		ft_vsnprintf(char *str, size_t maxlen, const char *fmt, va_list args);
int		ft_vsprintf(char *str, const char *format, va_list args);
int		ft_vdprintf(int fd, const char *format, va_list args);
int		ft_vprintf(const char *format, va_list args);

void	ft_set_format(t_format *f, const char *str, size_t *i, va_list args);

size_t	ft_convert(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_char(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_string(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_percent(char *str, size_t maxlen);

size_t	ft_convert_int(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_uint(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_hex(t_format *f, char *str, size_t maxlen, va_list args);
size_t	ft_convert_ptr(t_format *f, char *str, size_t maxlen, va_list args);

size_t	ft_ubase_countdigits(unsigned int n, size_t base);
size_t	ft_ulbase_countdigits(unsigned long n, size_t base);

size_t	ft_uint_countlen(t_format *f, unsigned int n);
size_t	ft_int_countlen(t_format *f, int n);
size_t	ft_hex_countlen(t_format *f, unsigned int n);
size_t	ft_ptr_countlen(t_format *f, unsigned long n);

void	ft_sutoa(char *str, t_format *f, unsigned int n);
void	ft_sitoa(char *str, t_format *f, int n);
void	ft_sutoh(char *str, t_format *f, unsigned int n);
void	ft_sultoh(char *str, t_format *f, unsigned long n);

size_t	ft_max(size_t a, size_t b);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);

#endif