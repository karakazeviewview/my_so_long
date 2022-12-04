/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:16:42 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 23:38:13 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_err(struct s_game *game)
{
	(void)game;
	write(1, "Error\n", 6);
	exit (0);
}

void	err_exit(struct s_game *game, char *msg)
{
	char	**map;
	int		i;

	(void)msg;
	map = game->map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(game);
	write(1, "Error\n", 6);
	exit (0);
}
