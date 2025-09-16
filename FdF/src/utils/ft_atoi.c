/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:29:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/09/16 14:35:31 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
