/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:46:40 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/21 17:43:16 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H

# include "structures.h"

void set_pixel(t_data *data, int x, int y, int color);
int render(void *param);

#endif