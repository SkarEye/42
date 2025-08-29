/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:27:31 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/29 09:39:30 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_fdf
{
	void	*mlx;
	void	*win;

	char	*stash;
	char	*line;

	size_t	map_w;
	size_t	map_h;
	int		**map;
}	t_fdf;

#endif