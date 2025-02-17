/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:54:50 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/14 21:11:05 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int main(void)
{
    printf("%d\n", ft_isprint('A'));
    printf("%d\n", ft_isprint('B'));
    printf("%d\n", ft_isprint('5'));
    printf("%d\n", ft_isprint(130));
    printf("%d\n", ft_isprint('/'));
    return (0);
}*/