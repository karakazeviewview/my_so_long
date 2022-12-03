/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:04:57 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/03 15:35:35 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

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