/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:04:00 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/05 23:14:12 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dest && !src)
// 		return (dest);
// 	else if (dest == src)
// 		return (dest);
// 	while (i < n)
// 	{
// 		*((char *)dest + i) = *((char *)src + i);
// 		i++;
// 	}
// 	return (dest);
// }

char	*line_rest(const char *s, char **rest)
{
	size_t	i;
	char	*line_begin;
	char	*temp;

	if (!s)
		return (free(*rest), *rest = NULL, NULL);
	i = 0;
	while (s[i] != '\n')
		i++;
	line_begin = (char *) malloc(sizeof(char) * (i + 2));
	if (line_begin == NULL)
		return (free(*rest), *rest = NULL, NULL);
	ft_memcpy(line_begin, s, i + 1);
	line_begin[i + 1] = '\0';
	if (ft_strlen(s) - i == 1)
		return (free(*rest), *rest = NULL, line_begin);
	temp = *rest;
	*rest = (char *) malloc(sizeof(char) * (ft_strlen(s) - i));
	if (*rest == NULL)
		return (free(line_begin), free(temp), NULL);
	ft_memcpy(*rest, s + i + 1, ft_strlen(s) - (i + 1));
	(*rest)[ft_strlen(s) - i - 1] = '\0';
	return (free(temp), line_begin);
}

void	*ft_realloc(void *str1, void *str2, size_t size1, size_t size2)
{
	char	*ptr;

	ptr = (char *) malloc(sizeof(char) * (size1 + size2 + 1));
	if (ptr == NULL)
		return (free(str1), NULL);
	ft_memcpy(ptr, str1, size1);
	ft_memcpy(ptr + size1, str2, size2);
	ptr[size1 + size2] = '\0';
	free(str1);
	return (ptr);
}
