/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:05:06 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 21:39:54 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "42_libft/include/libft.h"

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
		put_err("invalid map\n");
	map = (char **)malloc(sizeof(char *) * 35);
	if (!map)
		put_err("malloc error\n");
	i = 0;
	while (i < 35)
		map[i++] = NULL;
	i = 0;
	while (i < 34)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (map);
}

void	load_map(struct s_game *game)
{
	int		i;
	int		j;
	char	**map;

	game->collect_count = 0;
	map = game->map;
	i = 0;
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
				game->collect_count++;
			j++;
		}
		i++;
	}
}

void	get_map_size(struct s_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
		i++;
	game->map_height = i;
	i = 0;
	while (game->map[0] && game->map[0][i])
		i++;
	game->map_width = i - 1;
}
