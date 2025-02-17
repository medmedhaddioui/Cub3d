/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:03:41 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/05 23:11:26 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	read_line(char *buf, char **rest, char **line, int fd)
{
	int		i;

	i = read(fd, buf, BUFFER_SIZE);
	if (i == -1)
		return (free(*line), free(*rest), *rest = NULL, 1);
	if (i == 0 && *rest && check_newline(*rest) == 0)
		return (*line = *rest, *rest = NULL, 2);
	if (i == 0 && *rest)
	{
		*line = line_rest(*rest, rest);
		if (*line == NULL)
			return (1);
	}
	if (i == 0)
		return (2);
	return (buf[i] = '\0', 0);
}

int	join_buffer_to_rest(char *buf, char **rest, char **line)
{
	*rest = ft_realloc(*rest, buf, ft_strlen(*rest), ft_strlen(buf));
	if (*rest == NULL)
		return (free(*line), 1);
	if (check_newline(*rest))
	{
		*line = line_rest(*rest, rest);
		if (*line == NULL)
			return (1);
		return (2);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	static char		*rest;
	char			buf[BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (free(rest), rest = NULL, NULL);
	while (1)
	{
		i = read_line(buf, &rest, &line, fd);
		if (i == 1)
			return (NULL);
		else if (i == 2)
			return (line);
		i = join_buffer_to_rest(buf, &rest, &line);
		if (i == 1)
			return (NULL);
		else if (i == 2)
			return (line);
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd, i = 0;

// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	while (i < 2)
// 	{
// 		printf ("%s", get_next_line(fd));
// 		i++;
// 	}
// 	return (0);
// }