/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:04:44 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/28 18:29:11 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool check_characters(struct s_game *game)
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
			//ar *strchr(const char *__s, int __c)
			else if (!strchr("10E", map[i][j]))
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	printf("collect_count = %zu\n", game->collect_count);
	return (true);
}

void check_for_walls()
{}

bool check_p_e_c(char **map)
{
	if (check_p(map) == false)
		return (false);
	if (/* e */ == false)
		return (false);
	if (/* c */ == false)
		return (false);
	return (true);
}

bool check_p(char **map)
{
	size_t x;
	size_t y;
	size_t p_count;
	
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

bool check_e(char **map)
{
	size_t x;
	size_t y;
	size_t e_count;
	
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
	if (e_count == 1)
		return (true);
	else
		return (false);
}

bool check_c(char **map)
{
	size_t x;
	size_t y;
	size_t c_count;
	
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

void err_exit(struct s_game *game, char *msg)
{
	char **map;
	int i = 0;

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

void check_if_rectangle()
{}

void check_map(struct s_game *game)
{
	if (!check_characters(game))
	{
		err_exit(game, "Invalid characters in map");
	}
}