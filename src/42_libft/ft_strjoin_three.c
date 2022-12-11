/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:53:18 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 20:00:08 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*ptr;
	char	*save;

	if (!s1 || !s2 || !s3)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!ptr)
		return (NULL);
	save = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	while (*s3)
		*ptr++ = *s3++;
	*ptr = 0;
	return (save);
}
