/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:22:54 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 11:36:21 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = len - 1;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i >= 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
	}
	return (dst);
}

// int main(void)
// {
//     char *dest1 = "hello world";
//     //char src1[] = "xxxxxxx";
//     //ft_memcpy(NULL, NULL, 0);
//     printf("%s\n", ft_memmove(NULL, dest1, 3));
//     return (0);
// }