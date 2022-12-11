/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:51:19 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 19:59:22 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static size_t	get_size(long n)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long n)
{
	char	*s;
	size_t	len;
	long	num;

	len = get_size(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	num = n;
	while (len--)
	{
		if (num < 0)
			s[len] = -(num % 10) + '0';
		else
			s[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}
