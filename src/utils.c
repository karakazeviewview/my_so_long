/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:54:36 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 09:03:43 by yshimoda         ###   ########.fr       */
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

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
