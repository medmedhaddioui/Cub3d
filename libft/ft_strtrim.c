/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:44:15 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 15:16:50 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;

	if (!set || !*set)
		return (ft_strdup(s1));
	else if (!s1)
		return (NULL);
	while (in_set(set, *s1))
		s1++;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (in_set(set, *(s1 + i)))
		i--;
	trim = (char *) ft_calloc(i + 2, sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_memcpy(trim, s1, i + 1);
	return (trim);
}

/*int main(void)
{
    char s1[] = "#+=/#hello i'm noaman oudrib, i'm a student#+=-+-/#";
    char *set = "#+-= /";
    char *trim = ft_strtrim(s1, set);
    printf("%s::\n", trim);
    return (0);
}*/