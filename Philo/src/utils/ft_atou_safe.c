/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:48:27 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/20 19:55:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atou_safe(const char *str, unsigned int *out)
{
	long	n;

	if (!str || !*str)
		return (1);
	n = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		n = n * 10 + (*(str++) - '0');
		if (n > INT_MAX) //uint max value ?
			return (1);
	}
	*out = n;
	return (0);
}
