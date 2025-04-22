/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:26:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/22 17:33:03 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	if (!tab || !f)
		return (0);
	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i++]) == 1)
			count++;
	}
	return (count);
}