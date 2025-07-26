/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:27:59 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/22 15:18:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_UTILS_H
# define LINE_UTILS_H

# include <stddef.h>
# include <stdbool.h>

# include "structures.h"

size_t	get_line_len(const char *str, size_t max_p_w);
bool	is_end_of_line(const char *str, size_t max_p_w);
size_t	get_pixel_offset(const char *str, t_text_info *txt_i);

#endif