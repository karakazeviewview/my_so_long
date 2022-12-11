/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:54:36 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 21:45:43 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr2(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s)[i] !=
		(unsigned char)c && s[i] != 0)
	{
		i++;
	}
	if (((unsigned char *)s)[i] == (unsigned char)c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}

void	ft_write_number(int number)
{
	const char	str[10] = "0123456789";

	if (number > 9)
		ft_write_number(number / 10);
	write (1, &str[number % 10], 1);
}

char	**cpy_map(struct s_game *game)
{
	char	**map;
	char	**res;
	int		i;
	int		j;

	map = game->map;
	res = malloc(sizeof(char *) * game->map_height);
	if (!res)
		perror("malloc Error");
	i = 0;
	while (map[i] && i < game->map_height)
	{
		j = 0;
		res[i] = malloc(sizeof(char) * game->map_width);
		if (!res[i])
			perror("malloc Error");
		while (map[i][j] && j < game->map_width)
		{
			res[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
