/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forrest <forrest@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:11:19 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/10 18:04:10 by forrest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s1);
	dup = (char *) malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, i);
	dup[i] = 0;
	return (dup);
}

/*int main(void)
{
    char *str = "";
    //char *str2 = ft_strdup(str);
    
    printf("%p ::\n", ft_strdup(str));
    // free (str2);
    return (0);
}*/