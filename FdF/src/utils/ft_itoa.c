/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:44:54 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/15 15:46:15 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	get_size(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
		count++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	get_pow(int n)
{
	size_t	pow;

	pow = 1;
	while (n > 10 || n < -10)
	{
		n /= 10;
		pow *= 10;
	}
	return (pow);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n > 0)
		n = -n;
	else if (n < 0)
		str[0] = '-';
	else
		str[0] = '0';
	str[size--] = '\0';
	while (n > 0)
	{
		str[size--] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}

/***
 * @param dst Destination buffer
 * @param n The integer to convert
 * @return Length of the integer representation
 */
size_t	ft_sitoa(char *dst, int n)
{
	int		pow;
	size_t	i;

	if (!dst)
		return (get_size(n));
	pow = get_pow(n);
	i = 0;
	if (n < 0)
		dst[i++] = '-';
	else
		n *= -1;
	while (pow != 0)
	{
		dst[i++] = '0' - (n / pow);
		n %= pow;
		pow /= 10;
	}
	dst[i] = '\0';
	return (i);
}
