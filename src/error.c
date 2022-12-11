/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:16:42 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:02:03 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "42_libft/include/libft.h"

void	put_err(const char *str)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	exit (EXIT_FAILURE);
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
