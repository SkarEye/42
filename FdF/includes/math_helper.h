/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:07:49 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:24:56 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HELPER_H

# define MATH_HELPER_H

#include <math.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define PI	3.14159265358979323846


float	rad(float deg);
float	deg(float rad);
int		abs(int n);

#endif