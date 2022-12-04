/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:05:06 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 14:50:07 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int key_code, struct s_game *game)
{
	game->key_code = key_code;
	game->player_old_y = game->player_y;
	game->player_old_x = game->player_x;
	return (0);
}

char	**input_map(char *file_name)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		put_err(NULL);
	}
	map = (char **)malloc(sizeof(char *) * 55);
	map[0] = mini_get_next_line(fd);
	i = 0;
	while (map[i] != NULL && i < 55)
	{
		i++;
		map[i] = mini_get_next_line(fd);
	}
	return (map);
}
