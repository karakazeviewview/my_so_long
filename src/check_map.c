/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:04:44 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/03 16:11:13 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
	if (e_count >= 1)
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

bool check_p_e_c(char **map)
{
	if (check_p(map) == false)
		return (false);
	if (check_e(map) == false)
		return (false);
	if (check_c(map) == false)
		return (false);
	return (true);
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

void check_if_rectangle(struct s_game *game)
{
    size_t    len;
    size_t    i;

    len = strlen(game->map[0]);
    i = 1;
    while (game->map[i])
    {
        if (len != strlen(game->map[i]))
            printf("error");
        i++;
    }
}

/*
void check_map(struct s_game *game)
{
	if (!check_characters(game))
	{
		err_exit(game, "Invalid characters in map");
	}
}
*/

void check_invalid_tile(struct s_game *game)
{
    size_t    i;
    size_t    j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (!strchr("01PCE", game->map[i][j]))
                printf("error");
            j++;
        }
    }
}

// void que_add_back(struct s_node *ptr)
// {

// }


// struct s_node *que_take_front()
// {
// 	return (NULL);
// }


void get_map_size(struct s_game *game)
{
	
		size_t i = 0;
	while (game->map[i])
		i++;
	game->map_height = i;	
	i = 0;
	while (game->map[0][i])
		i++;
	game->map_width = i;
}

void all_err_check(struct s_game *game)
{
	check_characters(game);
	get_map_size(game);
	check_p_e_c(game->map);
	check_if_rectangle(game);
}