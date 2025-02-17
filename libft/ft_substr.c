/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:27:13 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 15:08:26 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (len == 0 || start >= j)
		return (ft_strdup(""));
	else if (len > j - start)
		len = j - start;
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s + start, len);
	return (str);
}

/*int main(void)
{
    char s[] = "hello i'm noaman oudrib, i'm a student at 1337";
    char *str = ft_substr(s, 10, 10);
    printf("%s::\n", str);
    return (0);
}*/