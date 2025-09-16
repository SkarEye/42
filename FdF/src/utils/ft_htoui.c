/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:29:26 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 14:35:18 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define HEX	"0123456789ABCDEF"

static bool	is_hex(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (true);
	return (false);
}

unsigned int	ft_htoui(const char *str)
{
	unsigned int	n;

	if (!str || !*str)
		return (0);
	if (*(str + 1) && *str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	n = 0;
	while (*str && is_hex(*str))
	{
		if (*str >= '0' && *str <= '9')
			n = n * 16 + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			n = n * 16 + (*str - 'a' + 10);
		else
			n = n * 16 + (*str - 'A' + 10);
		str++;
	}
	return (n);
}
