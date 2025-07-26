/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:37:02 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/19 18:44:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    // 1. Basic unsigned
    ret1 = ft_printf("Basic: [%u]\n", 12345u);
    ret2 = printf("Basic: [%u]\n", 12345u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 2. Zero value
    ret1 = ft_printf("Zero: [%u]\n", 0u);
    ret2 = printf("Zero: [%u]\n", 0u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 3. Width
    ret1 = ft_printf("Width: [%10u]\n", 42u);
    ret2 = printf("Width: [%10u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 4. Left-justified
    ret1 = ft_printf("Left-just: [%-10u]\n", 42u);
    ret2 = printf("Left-just: [%-10u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 5. Zero-padding
    ret1 = ft_printf("Zero-pad: [%010u]\n", 42u);
    ret2 = printf("Zero-pad: [%010u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 6. Precision only
    ret1 = ft_printf("Prec: [%.5u]\n", 42u);
    ret2 = printf("Prec: [%.5u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 7. Width + Precision
    ret1 = ft_printf("Width+Prec: [%10.5u]\n", 42u);
    ret2 = printf("Width+Prec: [%10.5u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 8. Zero-padding ignored with precision
    ret1 = ft_printf("Zero+Prec: [%010.5u]\n", 42u);
    ret2 = printf("Zero+Prec: [%010.5u]\n", 42u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 9. Precision 0 with value 0
    ret1 = ft_printf("Zero val, prec 0: [%6.0u]\n", 0u);
    ret2 = printf("Zero val, prec 0: [%6.0u]\n", 0u);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    // 10. UINT_MAX
    ret1 = ft_printf("UINT_MAX: [%u]\n", UINT_MAX);
    ret2 = printf("UINT_MAX: [%u]\n", UINT_MAX);
    printf("ft: %d | real: %d\n\n", ret1, ret2);

    return (0);
}