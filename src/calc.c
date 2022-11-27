/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:04:57 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/27 21:11:02 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(struct s_game *game)
{
	int bufx = 0;
	int bufy = 0;

	game->win_ptr = mlx_new_window(game->mlx_ptr, 500, 500, "mlx 42");
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr, IMG_WALL, &bufx, &bufy); 
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr, IMG_FLOOR, &bufx, &bufy);
	game->img.player_img = mlx_xpm_file_to_image(game->mlx_ptr, IMG_PLAYER, &bufx, &bufy);
	game->img.collection_img = mlx_xpm_file_to_image(game->mlx_ptr, IMG_COLLECTION, &bufx, &bufy);
	game->img.exit_img = mlx_xpm_file_to_image(game->mlx_ptr, IMG_EXIT, &bufx, &bufy);
}

void exit_game(struct s_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
	mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
	mlx_destroy_image(game->mlx_ptr, game->img.player_img);
	mlx_destroy_image(game->mlx_ptr, game->img.collection_img);
	mlx_destroy_image(game->mlx_ptr, game->img.exit_img);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	printf("hello\n");
	free(game);
	exit(0);
}

char *mini_get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] = '\0';
    return(buffer);
}

void check_map(struct s_game *game)
{
	int i = 0;
	int j;
	char **map;

	game->collect_count = 0;
	map = game->map;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (map[i][j] == 'C')
			{
				game->collect_count++;
			}
			j++;
		}
		i++;
	}
	printf("collect_count = %zu\n", game->collect_count);
}

bool check_collision(struct s_game *game, int player_next_y, int player_next_x)
{

	if (game->map[player_next_y][player_next_x] == '1')
	{
		return (true);
	}
	if (game->map[player_next_y][player_next_x] == 'C')
	{
		game->collect_count--;
		return (false);
	}
	if (game->map[player_next_y][player_next_x] == 'E') 
	{
		if  (game->collect_count == 0 )
		{
			exit_game(game);
		}
		else
		{
			return (true);
		}
	}
	return (false);
}

int move_player(struct s_game *game)
{
	if (game->key_code == KEY_UP)
	{
		printf("hello\n");
		if (check_collision(game, game->player_y - 1, game->player_x  ) == true)
		{
			return (0);
		}
		game->player_y = (game->player_y - 1)  ;
	}
	if (game->key_code == KEY_LEFT)
	{
		if (check_collision(game, game->player_y, game->player_x - 1) == true)
		{
			return (0);
		}
		else
		game->player_x = (game->player_x - 1)  ;
	}
	if (game->key_code == KEY_DOWN)
	{
		if (check_collision(game, game->player_y + 1, game->player_x  ) == true)
		{
			return (0);
		}
		game->player_y = (game->player_y + 1)  ;
	}
	if (game->key_code == KEY_RIGHT)
	{
		if (check_collision(game, game->player_y, game->player_x + 1) == true)
		{
			return (0);
		}
		else
		{
			game->player_x = (game->player_x + 1)  ;
		}
	}
	return (0);
}

int update_game(struct s_game *game)
{
	move_player(game);
	display_player(game);
	return (0);
}