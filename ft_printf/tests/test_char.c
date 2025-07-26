/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:58:01 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/19 15:04:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    // 1. Basic character
    ret1 = ft_printf("A: [%c]\n", 'A');
    ret2 = printf("A: [%c]\n", 'A');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 2. Width
    ret1 = ft_printf("Width: [%5c]\n", 'B');
    ret2 = printf("Width: [%5c]\n", 'B');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 3. Left-justified
    ret1 = ft_printf("Left: [%-5c]\n", 'C');
    ret2 = printf("Left: [%-5c]\n", 'C');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 4. Zero-padding (should be ignored)
    ret1 = ft_printf("Zero ignored: [%05c]\n", 'D');
    ret2 = printf("Zero ignored: [%05c]\n", 'D');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 5. Null character
    ret1 = ft_printf("Null char: [%c]\n", '\0');
    ret2 = printf("Null char: [%c]\n", '\0');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 6. Null character with width
    ret1 = ft_printf("Null width: [%5c]\n", '\0');
    ret2 = printf("Null width: [%5c]\n", '\0');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 7. Left-justified null character with width
    ret1 = ft_printf("Null left: [%-5c]\n", '\0');
    ret2 = printf("Null left: [%-5c]\n", '\0');
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    return (0);
}