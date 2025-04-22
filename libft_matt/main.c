/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:26:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/04/09 17:26:45 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Usage: ./a.out <number>\n", 24);
        return (1);
    }
    int number = ft_atoi(argv[1]);
    ft_putnbr_fd(number, 1);
    write(1, "\n", 1);
    return (0);
}