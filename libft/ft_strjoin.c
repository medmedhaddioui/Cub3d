/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:50:56 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 15:13:50 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *) ft_calloc(i + j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	return (str);
}

/*int main(void)
{
    char *str1 = "hello i'm noaman oudrib";
    char *str2 = ", i'm a student at 1337";
    char *str_join = ft_strjoin(str1, str2);

    printf("%s\n", str_join);
    return (0);
}*/