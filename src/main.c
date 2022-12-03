/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:59:29 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 01:07:17 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	struct s_game *game;

	game = malloc(sizeof(struct s_game));
	game->player_y = 0;
	game->player_x = 0;
	game->player_old_y = 0;
	game->player_old_x = 0;
	game->collect_count = 0;
	game->mlx_ptr = mlx_init();
	game->map = input_map(file_name);
	game->key_code = -1;
	check_map(game);
	all_err_check(game);
	init_game(game);
	display_img(game);
	mlx_key_hook(game->win_ptr, input_key, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}