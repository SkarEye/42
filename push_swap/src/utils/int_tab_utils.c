/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:05:51 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 12:36:54 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

#include "structures.h"

static int ft_atoi_safe(const char *str, int *out)
{
    long    n;
    int     sign;
    
    sign = 1;
    if (!str || !*str)
        return (0);
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
        return (0);
    n = 0;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        n = n * 10 + (*(str++) - '0');
        if ((sign == 1 && n > INT_MAX) || (sign == -1 && -n < INT_MIN))
            return (0);
    }
    *out = sign * n;
    return (1);
}

static int has_duplicates(int *tab, int n, size_t size)
{
    size_t i;

    if (!tab)
        return (0);
    i = 0;
    while (i < size)
    {
        if (tab[i] == n)
            return (1);
        i++;
    }
    return (0);
}

int *create_unique_int_tab(char **str_tab, size_t size)
{
    int *int_tab;
    int n;
    size_t i;

    int_tab = malloc(sizeof(int) * size);
    if (!int_tab)
        return (NULL);
    i = 0;
    while (i < size)
    {
        if (!ft_atoi_safe(str_tab[i], &n))
            return (free(int_tab), NULL);
        if (has_duplicates(int_tab, n, i))
            return (free(int_tab), NULL);
        int_tab[i] = n;
        i++;
    }
    return (int_tab);
}

void sort_int_tab(int *tab, size_t size)
{
    size_t i;
    size_t j;
    int temp;

i = 0;
    while (i < size - 1)
    {
        j = 0;
        while ( j < size - i - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
