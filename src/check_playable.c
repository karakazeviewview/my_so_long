/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:15:36 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 23:22:57 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
