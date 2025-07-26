/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unwanted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:17:13 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/21 18:17:22 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t get_space_amount(const char *str, size_t max_p_w)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '\n' && (i + 1)* GLYPH_WIDTH <= max_p_w)
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

bool	is_end_of_line(const char *str, size_t max_p_w)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n' && (i + 1)* GLYPH_WIDTH <= max_p_w)
		i++;
	if (!str[i] || str[i] == '\n')
		return (true);
	else
		return (false);
}