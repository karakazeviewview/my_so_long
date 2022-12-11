/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:51:39 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 19:59:31 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (!src && !dst)
		return (0);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

// C99 introduces the RESTRICT modifier to explicitly
// indicate that it refers to a different region.
