/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:31:08 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/15 17:14:25 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ubase_countdigits(unsigned int n, size_t base)
{
	size_t	digits;

	digits = 0;
	if (base < 2 || base > 36)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

size_t	ft_ulbase_countdigits(unsigned long n, size_t base)
{
	size_t	digits;

	digits = 0;
	if (base < 2 || base > 36)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		digits++;
	}
	return (digits);
}
