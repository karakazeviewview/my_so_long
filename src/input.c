/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:05:06 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/27 21:11:10 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input_key(int key_code, struct s_game *game)
{
	//printf("%d\n", key_code);
	game->key_code = key_code;
	game->player_old_y = game->player_y;
	game->player_old_x = game->player_x;
	//printf("%d %d\n", game->player_x, game->player_y);
	return (0);
}

char **input_map(char *file_name)
{
	int fd;
	fd = open(file_name, O_RDONLY);
	char **map;
	map = (char**)malloc(sizeof(char*) * 100);
	map[0] = mini_get_next_line(fd);
	int i = 0;
	while(map[i] != NULL)
	{
		i++;
		map[i] = mini_get_next_line(fd);
	}
	return (map);
}
