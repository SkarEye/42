/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:27:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/25 16:19:54 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_H
# define FT_PF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_print_itoa(int n);
void	ft_print_utoa(unsigned int n);
void	ft_print_itoh(unsigned int n, char c);

int		ft_printf(const char *format, ...);

#endif