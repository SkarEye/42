/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:00:18 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/25 16:32:40 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf.h"

size_t	ft_count_dec(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
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

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_count_dec(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	if (n < 0)
		str[0] = '-';
	if (n > 0)
		n *= -1;
	while (n != 0)
	{
		str[size--] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}

size_t	ft_count_hex(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}


void	ft_print_itoh(unsigned int n, char c)
{
	char	*str;
	size_t	size;

	size = ft_count_hex(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return ;
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
}