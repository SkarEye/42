/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:19:42 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/01 12:36:52 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "math_helper.h"

double	rad(double deg)
{
	return (deg * PI / 180.0);
}

double	deg(double rad)
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
