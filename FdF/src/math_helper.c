/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:19:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 21:25:07 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "math_helper.h"

float	rad(float deg)
{
	return (deg * PI / 180.0);
}

float	deg(float rad)
{
	return (rad * 180.0 / PI);
}

int	abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	else if (n < 0)
		return (-n);
	return (n);
}
