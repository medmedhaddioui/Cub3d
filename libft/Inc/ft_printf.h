/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:47:45 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 17:58:23 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		printf_char_fd(char c, int fd);
int		printf_str_fd(char *s, int fd);
int		printf_nbr_fd(long n, int fd);
int		printf_addr_hex(unsigned long a);
int		printf_hex(unsigned int n, char c);
int		printf_unsi_nbr(unsigned int n, int fd);
int		ft_printf(const char *s, ...);
#endif
