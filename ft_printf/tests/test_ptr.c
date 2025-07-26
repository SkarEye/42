/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:23:53 by macarnie          #+#    #+#             */
/*   Updated: 2025/05/21 13:24:59 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "ft_printf.h"

int main(void)
{
    void *ptr_valid = (void *)0x1234abcd;
    void *ptr_null = NULL;

    printf("\n========== POINTER (%%p) TESTS ==========\n");

    // 1. Basic valid pointer
    printf("PRINTF   : [%p]\n", ptr_valid);
    ft_printf("FT_PRINTF: [%p]\n", ptr_valid);

    // 2. NULL pointer
    printf("PRINTF   : [%p]\n", ptr_null);
    ft_printf("FT_PRINTF: [%p]\n", ptr_null);

    // 3. Left aligned
    printf("PRINTF   : [%-20p]\n", ptr_valid);
    ft_printf("FT_PRINTF: [%-20p]\n", ptr_valid);

    // 4. Right aligned with width
    printf("PRINTF   : [%20p]\n", ptr_valid);
    ft_printf("FT_PRINTF: [%20p]\n", ptr_valid);

    // 5. Precision (should be ignored for %p)
    printf("PRINTF   : [%.5p]\n", ptr_valid);
    ft_printf("FT_PRINTF: [%.5p]\n", ptr_valid);

    // 6. Width and precision (still: precision ignored)
    printf("PRINTF   : [%20.5p]\n", ptr_valid);
    ft_printf("FT_PRINTF: [%20.5p]\n", ptr_valid);

    // 7. Pointer to dynamically allocated memory
    char *str = malloc(10);
    printf("PRINTF   : [%p]\n", str);
    ft_printf("FT_PRINTF: [%p]\n", str);
    free(str);

    // 8. Multiple pointer args
    printf("PRINTF   : [%p %p %p]\n", ptr_valid, ptr_null, &ptr_valid);
    ft_printf("FT_PRINTF: [%p %p %p]\n", ptr_valid, ptr_null, &ptr_valid);

    return 0;
}
