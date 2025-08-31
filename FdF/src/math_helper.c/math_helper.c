/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:50:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/31 14:11:20 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "math_helper.h"

inline double	rad(double deg)
{
	return (deg * PI / 180.0);
}

inline double	deg(double rad)
{
	return (rad * 180.0 / PI);
}

