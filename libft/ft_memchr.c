/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:12:47 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 15:09:59 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (*((unsigned char *)s) != (unsigned char)c && --n)
		s++;
	if (*((unsigned char *)s) == (unsigned char)c)
		return ((void *)s);
	return (NULL);
}

/*int main(void)
{
    //char str[] = "";
    //str[4] = 0;
    //printf("%s\n", (char *)ft_memchr("hello i'm noaman", 'a', 4));
    printf("%s\n", (char *)memchr(NULL, 'o', 6));
    //printf("%p\n", (char *)memchr("hello i'm noaman", 'o', 0));
    //printf("%s\n", (char *)ft_memchr("hello i'm noaman", 'x', 10));
    return (0);
}*/