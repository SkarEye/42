/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:24:29 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:34 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(~n + 1));
	return ((unsigned int)n);
}

unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}
