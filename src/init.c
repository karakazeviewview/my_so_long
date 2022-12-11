/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:12:24 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 10:34:56 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(struct s_game *game)
{
	int	bufx;
	int	bufy;

	bufx = 0;
	bufy = 0;
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_WALL, &bufx, &bufy);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_FLOOR, &bufx, &bufy);
	game->img.player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_PLAYER, &bufx, &bufy);
	game->img.collection_img = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_COLLECTION, &bufx, &bufy);
	game->img.exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_EXIT, &bufx, &bufy);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * 32,
			game->map_height * 32, "mlx 42");
}

void	exit_game(struct s_game *game)
{
	size_t	i;

	mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
	mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
	mlx_destroy_image(game->mlx_ptr, game->img.player_img);
	mlx_destroy_image(game->mlx_ptr, game->img.collection_img);
	mlx_destroy_image(game->mlx_ptr, game->img.exit_img);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	exit(0);
}
