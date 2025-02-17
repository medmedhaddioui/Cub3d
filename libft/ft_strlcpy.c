/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:27:42 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 14:36:10 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenth_src;

	i = 0;
	lenth_src = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lenth_src);
}

/*int main(void)
{
	char dst[30] = "hello i'm ";
	char *str ="noaman";
    //printf("%d\n", ft_strncmp(0, 0, 0));
    printf("%lu\n", strlcpy(dst, str, 10));
    return (0);
}*/