/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:33:45 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 14:34:32 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_lenth;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	dest_lenth = ft_strlen(dst);
	if ((size <= dest_lenth) || (size == 0))
		return (size + ft_strlen(src));
	while (src[i] && i < size - dest_lenth - 1)
	{
		dst[dest_lenth + i] = src[i];
		i++;
	}
	dst[dest_lenth + i] = '\0';
	return (dest_lenth + ft_strlen(src));
}

/*int main(void)
{
	//char dst[30] = "hello i'm ";
	char *str ="noaman";
    //printf("%d\n", ft_strncmp(0, 0, 0));
    printf("%lu\n", ft_strlcat(NULL, str, 5));
    return (0);
}*/