/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:21 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:00:40 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < len)
		len = len_s;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && i + start < len_s)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
