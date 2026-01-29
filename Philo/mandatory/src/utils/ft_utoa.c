/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:52:05 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/26 16:55:03 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	get_size(unsigned int n)
{
	size_t	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	get_pow(unsigned int n)
{
	size_t	pow;

	pow = 1;
	while (n >= 10)
	{
		n /= 10;
		pow *= 10;
	}
	return (pow);
}

/**
 * @brief Convert an unsigned integer to a string.
 *
 * @param n The unsigned integer to convert
 * @return The string representation of the unsigned integer.
 */
char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	size;

	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (n != 0)
	{
		str[size--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

/**
 * @brief Convert an unsigned integer to a string and store it in the provided
 * buffer.
 *
 * @param dst Destination buffer
 * @param n The unsigned integer to convert
 * @return Length of the unsigned integer representation.
 */
size_t	ft_sutoa(char *dst, int n)
{
	int		pow;
	size_t	i;

	if (!dst)
		return (get_size(n));
	pow = get_pow(n);
	i = 0;
	while (pow != 0)
	{
		dst[i++] = '0' + (n / pow);
		n %= pow;
		pow /= 10;
	}
	dst[i] = '\0';
	return (i);
}
