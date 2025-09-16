/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:28:51 by macarnie          #+#    #+#             */
/*   Updated: 2025/09/16 14:59:24 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "structures.h"
#include "error_utils.h"

void	exit_fdf(t_debug dbg, t_error err, int exit_code, t_fdf *fdf)
{
	print_error(dbg, err, false);
	if (fdf)
	{
		if (fdf->mlx)
			mlx_destroy_display(fdf->mlx);
		free(fdf);
	}
	exit(exit_code);
}
