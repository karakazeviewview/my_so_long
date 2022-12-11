/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:53:56 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:00:29 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strndup(char const *s, size_t len)
{
	char	*tmp;
	char	*save;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	save = tmp;
	i = 0;
	while (i < len && *s)
	{
		*tmp++ = *s++;
		i++;
	}
	*tmp = '\0';
	return (save);
}
