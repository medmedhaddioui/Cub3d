/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:55:35 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 12:23:39 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!big && !len)
		return (NULL);
	else if (*little == 0)
		return ((char *)big);
	j = ft_strlen(little);
	while (ft_strncmp(big + i, little, j) != 0 && big[i])
		i++;
	if (len <= i || !big[i])
		return (NULL);
	else if (len - i < j)
		return (NULL);
	return ((char *)big + i);
}

/*int main(void)
{
    char big[] = "aaabcabcd";
    //char little[] = "cd";
    printf("%s\n", ft_strnstr(big, NULL, 5));
    //printf("%s\n", strnstr(big, little, 3));
}*/