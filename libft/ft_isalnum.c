/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:55:14 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/14 21:10:09 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*int main(void)
{
    printf("%d\n", ft_isalnum('A'));
    printf("%d\n", ft_isalnum('0'));
    printf("%d\n", ft_isalnum('9'));
    printf("%d\n", ft_isalnum('4'));
    printf("%d\n", ft_isalnum(';'));
    printf("%d\n", ft_isalnum('7'));
    return (0);
}*/