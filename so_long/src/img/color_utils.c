/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:21:13 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/08 14:59:22 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_utils.h"

unsigned int	blend_colors(unsigned int src_c, unsigned int dst_c, double a)
{
	int	r;
	int	g;
	int	b;

	// edge cases for when a < 0 or a > 1 ?
	r = ((1 - a) * ((src_c >> 16) & 0xFF)) + (a * ((dst_c >> 16) & 0xFF));
	g = ((1 - a) * ((src_c >> 8) & 0xFF)) + (a * ((dst_c >> 8) & 0xFF));
	b = ((1 - a) * (src_c & 0xFF)) + (a * (dst_c & 0xFF));
	return (r << 16 | g << 8 | b);
}
