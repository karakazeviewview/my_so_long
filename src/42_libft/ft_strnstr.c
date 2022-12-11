/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:02 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:00:32 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && i + j < len && haystack[i
				+ j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
