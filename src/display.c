/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:04:35 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/27 21:10:32 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_grid(void *mlx_ptr, void *win_ptr, struct IMG img, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.wall_img, x, y);
	if (tile == '0')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.floor_img, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.collection_img, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.exit_img, x, y);
}

void display_img(struct s_game *game)
{
	int bufx = 0;
	int bufy = 0;

	int i = 0;
	while (game->map[i] != NULL)
	{
		int j = 0;
		while (game->map[i][j] != '\0')
		{
			display_grid(game->mlx_ptr, game->win_ptr, game->img, j * 59, i * 59, game->map[i][j]);
			j++;
		}
		i++;
	}
	display_player(game);
}

int display_player(struct s_game *game)
{
	int x;
	int y;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_img  , game->player_x * 59, game->player_y * 59);
	if (game->key_code != -1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, game->player_old_x * 59, game->player_old_y * 59);
		game->key_code = -1;
	}
	//printf("game->pox%d\n", game->player_old_x);
	return (0);
}

