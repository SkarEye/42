/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:05:51 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/06/04 19:59:30 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(const char *str)
{
    int sign;
    int n;

    n = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    return (sign * n);
}

int *create_unique_int_tab(char **str_tab, size_t size)
{
    int *int_tab;
    size_t i;
    size_t j;

    int_tab = malloc(sizeof(int) * size);
    if (!int_tab)
        return (NULL);
    i = 0;
    while (i < size)
    {
        int_tab[i] = ft_atoi(str_tab[i]);
        j = 0;
        while (j < i)
        {
            if (int_tab[j] == int_tab[i])
                return (free(int_tab), NULL);
            j++;
        }
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
