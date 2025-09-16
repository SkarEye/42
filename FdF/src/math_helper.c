/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:19:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:29:39 by mattcarniel      ###   ########.fr       */
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

float	normalize_angle(float a)
{
	a = fmodf(a, 2.0f * PI);
	if (a < 0)
		a += 2.0f * PI;
	return (a);
}

int	abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	else if (n < 0)
		return (-n);
	return (n);
}
