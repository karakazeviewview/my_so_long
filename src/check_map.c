/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:04:44 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 13:05:48 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(struct s_game *game)
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
	printf("collect_count = %zu\n", game->collect_count);
}

bool	check_p(char **map)
{
	size_t	x;
	size_t	y;
	size_t	p_count;

	y = 0;
	p_count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				p_count++;
			x++;
		}
		y++;
	}
	if (p_count == 1)
		return (true);
	else
		return (false);
}

bool	check_e(char **map)
{
	size_t	x;
	size_t	y;
	size_t	e_count;

	y = 0;
	e_count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'E')
				e_count++;
			x++;
		}
		y++;
	}
	if (e_count >= 1)
		return (true);
	else
		return (false);
}

bool	check_c(char **map)
{
	size_t	x;
	size_t	y;
	size_t	c_count;

	y = 0;
	c_count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	if (c_count >= 1)
		return (true);
	else
		return (false);
}

bool	check_p_e_c(char **map)
{
	if (check_p(map) == false)
		return (false);
	if (check_e(map) == false)
		return (false);
	if (check_c(map) == false)
		return (false);
	return (true);
}

void	put_err(struct s_game *game)
{
	printf("Error\n");
	exit (0);
}

void	err_exit(struct s_game *game, char *msg)
{
	char	**map;
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(game);
	printf("Error\n");
	printf("%s\n", msg);
	exit (0);
}

void	check_if_rectangle(struct s_game *game)
{
	size_t	len;
	size_t	i;

	len = strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (i == game->map_height - 1)
		{
			if (len != strlen(game->map[i]) + 1)
				put_err(game);
		}		
		else
		{
			if (len != strlen(game->map[i]))
				put_err(game);
		}
		i++;
	}
}

bool	check_invalid_tile(struct s_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("%d\n", game->map_height);
	printf("%d\n", game->map_width);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			printf("%c", game->map[i][j]);
			if (!strchr("01PCE\n", game->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	explorer_map(char **map, int player_x,
		int player_y, struct s_game *game)
{
	int	x;
	int	y;	

	x = player_x;
	y = player_y;
	if (x == -1 || x == game->map_width || y == -1 || y == game->map_height)
	{
		put_err(game);
	}
	else if (map[y][x] != CHECKED && map[y][x] != '1')
	{
		map[y][x] = CHECKED;
		explorer_map(map, x + 1, y, game);
		explorer_map(map, x - 1, y, game);
		explorer_map(map, x, y + 1, game);
		explorer_map(map, x, y - 1, game);
	}
}

char	**cpy_map(struct s_game *game)
{
	char	**map;
	char	**res;
	int		i;
	int		j;

	map = game->map;
	res = malloc(sizeof(char *) * game->map_height);
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		res[i] = malloc(sizeof(char) * game->map_width);
		while (j < game->map_width)
		{
			res[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (res);
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

void	check_map_size(struct s_game *game)
{
	if (game->map_height == 0 || game->map_width == 0)
	{
		put_err(game);
	}
	if (game->map_height > 50 || game->map_width > 50)
	{
		put_err(game);
	}
}

void	all_err_check(struct s_game *game)
{
	char	**cpied_map;

	get_map_size(game);
	check_map_size(game);
	cpied_map = cpy_map(game);
	explorer_map(cpied_map, game->player_x, game->player_y, game);
	if (check_p_e_c(game->map) == false)
		put_err(game);
	if (check_invalid_tile(game) == false)
		put_err(game);
	check_if_rectangle(game);
}
