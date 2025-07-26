/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:08 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/19 18:38:55 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret1, ret2;

    // 1. Basic positive and negative
    ret1 = ft_printf("Basic pos: [%d]\n", 42);
    ret2 = printf("Basic pos: [%d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    ret1 = ft_printf("Basic neg: [%d]\n", -42);
    ret2 = printf("Basic neg: [%d]\n", -42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 2. Width
    ret1 = ft_printf("Width: [%5d]\n", 42);
    ret2 = printf("Width: [%5d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 3. Left-justified
    ret1 = ft_printf("Left: [%-5d]\n", 42);
    ret2 = printf("Left: [%-5d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 4. Zero-padding
    ret1 = ft_printf("Zero pad: [%05d]\n", 42);
    ret2 = printf("Zero pad: [%05d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 5. Precision only
    ret1 = ft_printf("Prec: [%.5d]\n", 42);
    ret2 = printf("Prec: [%.5d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 6. Width + precision
    ret1 = ft_printf("Width+Prec: [%8.5d]\n", 42);
    ret2 = printf("Width+Prec: [%8.5d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 7. Sign flags
    ret1 = ft_printf("Plus: [%+d]\n", 42);
    ret2 = printf("Plus: [%+d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    ret1 = ft_printf("Space: [% d]\n", 42);
    ret2 = printf("Space: [% d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 8. Zero + precision combo (zero ignored)
    ret1 = ft_printf("Zero+prec: [%08.5d]\n", 42);
    ret2 = printf("Zero+prec: [%08.5d]\n", 42);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 9. 0 with precision 0
    ret1 = ft_printf("Zero val, prec 0: [%5.0d]\n", 0);
    ret2 = printf("Zero val, prec 0: [%5.0d]\n", 0);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 10. Edge limits
    ret1 = ft_printf("INT_MAX: [%d]\n", INT_MAX);
    ret2 = printf("INT_MAX: [%d]\n", INT_MAX);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    ret1 = ft_printf("INT_MIN: [%d]\n", INT_MIN);
    ret2 = printf("INT_MIN: [%d]\n", INT_MIN);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    return (0);
}