/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/13 16:20:47 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_strtab(char **strtab)
{
	size_t	i;

	if (!strtab)
		return ;
	i = 0;
	while (strtab[i])
		free(strtab[i++]);
	free(strtab);
}
