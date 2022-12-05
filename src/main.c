/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:59:02 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/05 19:47:18 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_game	*init_value(void)
{
	struct s_game	*g;

	g = malloc(sizeof(struct s_game));
	g->step_count = 0;
	g->map_height = 0;
	g->map_width = 0;
	g->player_y = 0;
	g->player_x = 0;
	g->key_code = -1;
	g->player_old_y = 0;
	g->player_old_x = 0;
	g->collect_count = 0;
	return (g);
}

int	main(int argc, char **argv)
{
	char			*file_name;
	struct s_game	*game;

	if (argc != 2)
	{
		write(1, "no arg ", 7);
		put_err(NULL);
	}
	file_name = argv[1];
	game = init_value();
	game->mlx_ptr = mlx_init();
	game->map = input_map(file_name);
	load_map(game);
	all_err_check(game);
	init_game(game);
	display_img(game);
	mlx_key_hook(game->win_ptr, input_key, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
/*
#include "so_long.h"

int	main(int argc, char **argv)
{
	char			*file_name;
	struct s_game	*game;

	file_name = argv[1];
	game = malloc(sizeof(struct s_game));
	game->player_y = 0;
	game->player_x = 0;
	game->player_old_y = 0;
	game->player_old_x = 0;
	game->collect_count = 0;
	game->mlx_ptr = mlx_init();
	game->map = input_map(file_name);
	game->key_code = -1;
	load_map(game);
	all_err_check(game);
	init_game(game);
	display_img(game);
	mlx_key_hook(game->win_ptr, input_key, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
*/