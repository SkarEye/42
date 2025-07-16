/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:03:27 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/15 16:10:19 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "exit_utils.h"
#include "structures.h"

static const char	*get_error_message(t_error err)
{
	static const char *error_msgs[] = {
		"Success !\n",
		"Invalid map.\n",
		"Map not surrounded by walls.\n",
		"Too many players.\n",
		"No player found.\n",
		"Too many exits.\n",
		"No exit found.\n",
		"No collectibles found.\n",
		"Invalid character in map.\n",
		"Map is not rectangular.\n",
		"Flood fill failed.\n",
		"Memory allocation failed.\n",
		"Failed to open file.\n",
		"Failed to read file.\n",
		"No filename provided.\n",
		"MLX initialization failed.\n",
		"Invalid file extension.\n",
		"Unknown error.\n"
	};

	if (err < 0 || err >= ERR_COUNT)
		return (error_msgs[ERR_UNKNOWN]);
	return (error_msgs[err]);
}

void	print_error(t_error err, const char *sys_context)
{
	dprintf(2, "Error in %s: %s", sys_context, get_error_message(err));
}

void	exit_window(void *mlx, void *win)
{
	if (win)
		mlx_destroy_window(mlx, win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	exit_game(t_error err, const char *sys_context, t_game *game)
{
	(void)game; // Placeholder for future game cleanup if needed
	// if (game)
	// 	free_game(game);
	if (err == ERR_NONE)
		exit(EXIT_SUCCESS);
	else
	{
		print_error(err, sys_context);
		exit(EXIT_FAILURE);
	}
}
