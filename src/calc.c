/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:04:57 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 17:45:30 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
char	*mini_get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	//buffer = malloc(10000);
	buffer = malloc(sizeof(char) * 10000);
	if (buffer == NULL)
		return (NULL);
	rd = 0;
	i = 0;
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	//if ((buffer[i - 1] != '\0' && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
*/

bool	check_collision(struct s_game *game,
		int player_next_y, int player_next_x)
{
	if (game->map[player_next_y][player_next_x] == '1')
	{
		game->key_code = -1;
		return (true);
	}
	if (game->map[player_next_y][player_next_x] == 'C')
	{
		game->collect_count--;
		game->map[player_next_y][player_next_x] = '0';
		return (false);
	}
	if (game->map[player_next_y][player_next_x] == 'E')
	{
		if (game->collect_count == 0)
			exit_game(game);
		else
		{
			game->key_code = -1;
			return (true);
		}
	}
	return (false);
}

int	move_player(struct s_game *game)
{
	if (game->key_code == KEY_UP || game->key_code == KEY_ARROW_UP)
	{
		if (check_collision(game, game->player_y - 1, game->player_x) == true)
			return (0);
		game->player_y = (game->player_y - 1);
	}
	if (game->key_code == KEY_LEFT || game->key_code == KEY_ARROW_LEFT)
	{
		if (check_collision(game, game->player_y, game->player_x - 1) == true)
			return (0);
		game->player_x = (game->player_x - 1);
	}
	if (game->key_code == KEY_DOWN || game->key_code == KEY_ARROW_DOWN)
	{
		if (check_collision(game, game->player_y + 1, game->player_x) == true)
			return (0);
		game->player_y = (game->player_y + 1);
	}
	if (game->key_code == KEY_RIGHT || game->key_code == KEY_ARROW_RIGHT)
	{
		if (check_collision(game, game->player_y, game->player_x + 1) == true)
			return (0);
		game->player_x = (game->player_x + 1);
	}
	return (0);
}

int	update_game(struct s_game *game)
{
	move_player(game);
	esc_game(game);
	display_player(game);
	return (0);
}

int	esc_game(struct s_game *game)
{
	if (game->key_code == KEY_ESC)
		exit_game(game);
	return (0);
}
