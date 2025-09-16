/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:19:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 20:08:23 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "math_helper.h"

/**
 * @brief Converts degrees into radians.
 *
 * @param deg Degree
 * @returns Radians.
 */
float	rad(float deg)
{
	return (deg * PI / 180.0);
}

/**
 * @brief Converts radians into degrees.
 *
 * @param deg Radians
 * @returns Degrees.
 */
float	deg(float rad)
{
	return (rad * 180.0 / PI);
}

/**
 * @brief Normalizes angle value so it is inbetween 0 and 2 * PI.
 *
 * @param a Angle in radians.
 * @returns Normalized angle in radians.
 */
float	normalize_angle(float a)
{
	a = fmodf(a, 2.0f * PI);
	if (a < 0)
		a += 2.0f * PI;
	return (a);
}

/**
 * @brief Returns the absolute value of an integer.
 *
 * @param n Integer
 * @returns Absolute value of n.
 * @note If n is equal to INT_MIN, defaults to give INT_MAX as a result.
 */
int	abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	else if (n < 0)
		return (-n);
	return (n);
}
