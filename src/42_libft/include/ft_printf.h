/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:48:45 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 19:48:46 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# define DEC "0123456789"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int			ft_printf(const char *format, ...);
ssize_t		ft_put_char(char c);
ssize_t		ft_put_str(char *str);
ssize_t		ft_put_ptr(uintptr_t num);

#endif