/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:10:39 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/07 12:42:47 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int ft_isalpha(int c)
{
    return (ft_islower(c) || ft_isupper(c));
}