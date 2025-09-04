/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:00:20 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/04 17:01:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_HELPER_H
# define TEXT_HELPER_H

# include <stddef.h>

#include "structures.h"

size_t	get_space_count(const char *str, size_t max_len);
size_t	get_word_len(const char *str);
size_t	get_line_len(const char *str, size_t max_len);
size_t	get_pixel_offset(const char *str, t_txt txt);

#endif