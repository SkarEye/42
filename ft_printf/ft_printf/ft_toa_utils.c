/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:20:33 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/13 13:21:43 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = (dst > src) * (n - 1);
	while (n--)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i += (dst < src) - (dst > src);
	}
	return (dst);
}

size_t	ft_sitoa(int n, char **str, size_t maxlen)
{
	size_t	size;
	size_t	i;

	size = ft_int_countdigits(n);
	if (n > 0)
		n *= -1;
	if (size > maxlen)
		return (size);
	if (n < 0)
		 (*str)[0] = '-';
	else if (n == 0)
		(*str)[0] = '0';
	i = 1;
	while (n != 0)
	{
		str[size - (i++)] = '0' - (n % 10);
		n /= 10;
	}
	return (size);
}

size_t	ft_sutoa(unsigned int n, char **str, size_t maxlen)
{
	size_t	size;
	size_t	i;

	size = ft_uint_countdigits(n);
	if (size > maxlen)
		return (size);
	if (n == 0)
		(*str)[0] = '0';
	i = 1;
	while (n != 0)
	{
		(*str)[size - (i++)] = '0' + (n % 10);
		n /= 10;
	}
	return (size);
}

size_t	ft_sutoh(unsigned int n, char **str, size_t maxlen)
{
	size_t	size;
	size_t	i;

	size = ft_hex_countdigits(n);
	if (size > maxlen)
		return ;
	if (n == 0)
		(*str)[0] = '0';
	i = 1;
	while (n != 0)
	{
		(*str)[size - (i++)] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
}