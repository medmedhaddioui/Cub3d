/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:26:08 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 17:14:02 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str_fd(char *str, int fd)
{
	if (fd < 0)
		return (0);
	if (!str)
		return (write(fd, "(null)", 6));
	if (write(fd, str, ft_strlen(str)) < 0)
		return (-1);
	return (ft_strlen(str));
}
