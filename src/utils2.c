/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:42:29 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 19:05:29 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_strchr(char	*s, int	c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *) &s[ft_strlen(s)]);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char	*s1, char	*s2)
// {
// 	size_t	i;
// 	size_t	c;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	c = 0;
// 	while (s1[++i] != '\0')
// 		str[i] = s1[i];
// 	while (s2[c] != '\0')
// 		str[i++] = s2[c++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }

// char	*ft_strdup(const char	*s1)
// {
// 	size_t	i;
// 	char	*s2;

// 	i = 0;
// 	while (s1[i])
// 		i++;
// 	s2 = (char *)malloc(i + 1);
// 	if (s2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		s2[i] = s1[i];
// 		i++;
// 	}
// 	s2[i] = '\0';
// 	return (s2);
// }