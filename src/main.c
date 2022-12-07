/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:59:02 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/08 04:20:40 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_game	*init_value(void)
{
	struct s_game	*g;

	g = malloc(sizeof(struct s_game));
	if (!g)
		put_err("malloc error\n");
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
		put_err("no arg\n");
	file_name = argv[1];
	game = init_value();
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		put_err("malloc error\n");
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