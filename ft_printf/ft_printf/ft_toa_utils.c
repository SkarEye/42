/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:00:18 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/24 15:00:49 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

size_t	ft_count_dec(int n, char pos)
{
	size_t	count;

	count = 0;
	if (pos == '+' || n < 0)
		count += 1;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n, char pos)
{
	char	*str;
	size_t	size;

	size = ft_count_dec(n, pos);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	if (n < 0)
		str[0] = '-';
	else if (pos == '+')
		str[0] = '+';
	if (n > 0)
		n *= -1;
	while (n != 0)
	{
		str[size--] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}

size_t	ft_count_hex(unsigned int n, char hash)
{
	size_t	count;

	count = 0;
	if (hash == '#')
		count += 2;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}


char	*ft_itoh(unsigned int n, char hash, char c)
{
	char	*str;
	size_t	size;

	size = ft_count_hex(n, hash);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (hash == '#')
	{
		str[0] = '0';
		printf("\n%c\n", c + 23);
		str[1] = c + 23;
	}
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	while (n != 0)
	{
		if (n % 16 < 10)
			str[size--] = '0' + (n % 16);
		else
			str[size--] = c + (n % 16 - 10);
		n /= 16;
	}
	return (str);
}