/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:27:23 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/24 14:56:10 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_H
# define FT_PF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

char	*ft_itoh(unsigned int n, char hash, char c);
char	*ft_itoa(int n, char pos);

#endif