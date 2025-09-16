/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:29:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 19:30:05 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer.
 *
 * @param str Character string
 * @return Converted integer.
 * @warning Values exceeding INT_MAX & INT_MIN are considered as undefined
 * @note If the string is invalid, will always return 0.
 * behavior.
 */
int	ft_atoi(const char *str)
{
	int		n;
	char	sign;

	sign = 1;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	n = 0;
	while (*str && *str >= '0' && *str <= '9')
		n = n * 10 + (*(str++) - '0');
	return (n);
}
