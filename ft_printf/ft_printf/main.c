/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:37:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/16 14:56:43 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    printf("\nft_printf  val : %d\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
    printf("\nprintf  val : %d\n", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
    return (0);
}