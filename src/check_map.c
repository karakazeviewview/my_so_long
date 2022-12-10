/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:14:07 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/08 03:12:43 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_rectangle(struct s_game *game)
{
	size_t	len;
	int		i;

	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (i == game->map_height - 1)
		{
			if (len != ft_strlen(game->map[i]) + 1)
				put_err("not rectangle\n");
		}		
		else
		{
			if (len != ft_strlen(game->map[i]))
				put_err("not rectangle\n");
		}
		i++;
	}
}

bool	check_invalid_tile(struct s_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (!ft_strchr2("01PCE\n", game->map[i][j]))
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
		put_err("not playable\n");
	else if (map[y][x] != CHECKED && map[y][x] != '1')
	{
		map[y][x] = CHECKED;
		explorer_map(map, x + 1, y, game);
		explorer_map(map, x - 1, y, game);
		explorer_map(map, x, y + 1, game);
		explorer_map(map, x, y - 1, game);
	}
}

void	check_map_size(struct s_game *game)
{
	if (game->map_height == 0 || game->map_width == 0)
		put_err("void line map\n");
	if (game->map_height > 50 || game->map_width > 50)
		put_err("too large\n");
}

void	all_err_check(struct s_game *game)
{
	char	**cpied_map;

	get_map_size(game);
	check_map_size(game);
	cpied_map = cpy_map(game);
	explorer_map(cpied_map, game->player_x, game->player_y, game);
	if (check_p_e_c(game->map) == false)
		put_err("wrong num of objects\n");
	if (check_invalid_tile(game) == false)
		put_err("invalid tile\n");
	check_if_rectangle(game);
}
