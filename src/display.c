/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:04:35 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 00:43:37 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_grid(struct s_game *game, int y, int x, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall_img, x, y);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.floor_img, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.collection_img, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit_img, x, y);
}

void	display_img(struct s_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			display_grid(game,
				i * 59, j * 59, game->map[i][j]);
			j++;
		}
		i++;
	}
	display_player(game);
}

void	put_step(struct s_game *game)
{
	ft_write_number(game->step_count);
	write(1, " steps", 6);
	write(1, "\n", 1);
	game->step_count++;
}

int	display_player(struct s_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_img,
		game->player_x * 59, game->player_y * 59);
	if (game->key_code == KEY_UP || game->key_code == KEY_DOWN
		|| game->key_code == KEY_LEFT || game->key_code == KEY_RIGHT
		|| game->key_code == KEY_ARROW_UP || game->key_code == KEY_ARROW_DOWN
		|| game->key_code == KEY_ARROW_LEFT || game->key_code == KEY_ARROW_RIGHT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.floor_img, game->player_old_x * 59,
			game->player_old_y * 59);
		put_step(game);
		game->key_code = -1;
	}
	return (0);
}
