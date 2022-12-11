/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:07 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:00:34 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s + ft_strlen(s);
	while (1)
	{
		if (*str == (char)c)
			return ((char *)str);
		if (str == s)
			return (NULL);
		str--;
	}
	return (NULL);
}
