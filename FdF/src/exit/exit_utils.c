/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:28:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 17:46:12 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "structures.h"
#include "image.h"
#include "exit_utils.h"

#include <stdio.h>

/**
 * @brief Safely exits the program after destroying all mlx entities and freeing
 * malloc'ed pointers.
 *
 * @param dbg Filename and line value
 * @param err Error type
 * @param exit_code Exit code value
 * @param fdf FDF struct pointer
 * @note 'dbg' and 'err' are used for the print_error function.
 */
void	exit_fdf(t_debug dbg, t_error err, int exit_code, t_fdf *fdf)
{
	print_error(dbg, err, false);
	if (fdf)
	{
		if (fdf->data)
			free_image(fdf->mlx, fdf->data);
		if (fdf->font)
			free_image(fdf->mlx, fdf->font);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		if (fdf->mlx)
		{
			mlx_destroy_display(fdf->mlx);
			xfree((void **)&fdf->mlx);
		}
		xfree((void **)&fdf->stash);
		xfree((void **)&fdf->line);
		xfree((void **)&fdf->map);
	}
	exit(exit_code);
}
