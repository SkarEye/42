/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:23:55 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/20 09:29:06 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    unsigned int zero = 0;
    unsigned int small = 42;
    unsigned int large = UINT_MAX;

    printf("\n========== HEXADECIMAL (%%x) TESTS ==========\n");

    // 1. Basic hex
    printf("PRINTF   : [%x]\n", small);
    ft_printf("FT_PRINTF: [%x]\n", small);

    // 2. Uppercase
    printf("PRINTF   : [%X]\n", small);
    ft_printf("FT_PRINTF: [%X]\n", small);

    // 3. Zero value
    printf("PRINTF   : [%x]\n", zero);
    ft_printf("FT_PRINTF: [%x]\n", zero);

    // 4. Precision 0 + zero
    printf("PRINTF   : [%.0x]\n", zero);
    ft_printf("FT_PRINTF: [%.0x]\n", zero);

    // 5. Hash + zero + precision 0
    printf("PRINTF   : [%#.0x]\n", zero);
    ft_printf("FT_PRINTF: [%#.0x]\n", zero);

    // 6. Hash + small
    printf("PRINTF   : [%#x]\n", small);
    ft_printf("FT_PRINTF: [%#x]\n", small);

    // 7. Hash + uppercase
    printf("PRINTF   : [%#X]\n", small);
    ft_printf("FT_PRINTF: [%#X]\n", small);

    // 8. Field width
    printf("PRINTF   : [%10x]\n", small);
    ft_printf("FT_PRINTF: [%10x]\n", small);

    // 9. Field width + left-align
    printf("PRINTF   : [%-10x]\n", small);
    ft_printf("FT_PRINTF: [%-10x]\n", small);

    // 10. Precision
    printf("PRINTF   : [%.5x]\n", small);
    ft_printf("FT_PRINTF: [%.5x]\n", small);

    // 11. Width + precision
    printf("PRINTF   : [%10.5x]\n", small);
    ft_printf("FT_PRINTF: [%10.5x]\n", small);

    // 12. Zero-padding (no precision)
    printf("PRINTF   : [%010x]\n", small);
    ft_printf("FT_PRINTF: [%010x]\n", small);

    // 13. Zero-padding + precision (zero ignored)
    printf("PRINTF   : [%010.5x]\n", small);
    ft_printf("FT_PRINTF: [%010.5x]\n", small);

    // 14. Hash + zero-padding
    printf("PRINTF   : [%#010x]\n", small);
    ft_printf("FT_PRINTF: [%#010x]\n", small);

    // 15. Hash + width + precision
    printf("PRINTF   : [%#10.5x]\n", small);
    ft_printf("FT_PRINTF: [%#10.5x]\n", small);

    // 16. Large value
    printf("PRINTF   : [%x]\n", large);
    ft_printf("FT_PRINTF: [%x]\n", large);

    // 17. Large value + hash
    printf("PRINTF   : [%#x]\n", large);
    ft_printf("FT_PRINTF: [%#x]\n", large);

    return 0;
}
