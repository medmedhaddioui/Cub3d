/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:55:02 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/14 21:10:56 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int main(void)
{
    printf("%d\n", ft_isascii('A'));
    printf("%d\n", ft_isascii('B'));
    printf("%d\n", ft_isascii('5'));
    printf("%d\n", ft_isascii(130));
    printf("%d\n", ft_isascii('/'));
    return (0);
}*/