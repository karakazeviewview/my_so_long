/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:07:50 by event             #+#    #+#             */
/*   Updated: 2022/12/12 22:18:57 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "42_libft/include/libft.h"

char	*check_file_name(char *arg)
{
	char	*file_name;

	if (ft_strlen(arg) < 4 || ft_strncmp(arg + ft_strlen(arg) - 4, \
	".ber", 4))
		put_err("name error\n");
	file_name = arg;
	return (file_name);
}
