/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:56:30 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/25 15:14:02 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_UTILS_H
# define TEXT_UTILS_H

# include "structures.h"

# ifndef GLYPH_WIDTH
#  define GLYPH_WIDTH 	8
# endif

# ifndef GLYPH_HEIGHT
#  define GLYPH_HEIGHT 	8
# endif

t_text_info	*set_text_info(int w, int h, int color, t_align align);
t_data	*text_to_image(void *mlx, t_data *font, const char *str,
		t_text_info *txt_i);
#endif