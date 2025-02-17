/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:12:47 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/15 16:19:47 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

/*int main(void)
{


    //char str1[] = "hello i'm noaman";
   // char str2[] = "aellx i'm noaman";
    //printf("%d\n", memcmp(0, "", 1));
    printf("%d\n", ft_memcmp(str1, str2, 5));
    printf("%d\n", memcmp(str1, str2, 1));
    printf("%d\n", memcmp(str1, str2, 5));
    return (0);
}*/