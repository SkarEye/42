/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:55:14 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 14:58:33 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
