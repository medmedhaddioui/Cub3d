/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:32:16 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/12/26 17:52:04 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

int	check_map_content(char *str)
{
	int	i;

	i = 0;
	if (is_newline(str))
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	if (!compare_tool(str + i))
		return (0);
	return (1);
}

void	check_error_type(char *line)
{
	char	**tmp_arr;
	int		i;
	int		j;
	bool	flag;

	tmp_arr = ft_split(line, '\n');
	i = 0;
	flag = false;
	while (tmp_arr[i])
	{
		j = 0;
		while (tmp_arr[i][j] && tmp_arr[i][j] == ' ')
			j++;
		if (compare_tool(&tmp_arr[i][j]))
			flag = true;
		else if (flag && !compare_tool(&tmp_arr[i][j]) && (free_arr(tmp_arr),
				1))
			ft_exit1("Error Map wrong arguments in map!\n", line);
		i++;
	}
	free_arr(tmp_arr);
	ft_exit1("Error Newline in map !\n", line);
}

int	check_map_newline(char *str, bool flag, int *fd, char *line)
{
	if (flag == true && is_newline(str))
	{
		free(str);
		str = get_next_line(*fd);
		while (str)
		{
			if (!is_newline(str))
				line = ft_strjoin_2(line, str);
			if (!is_newline(str) && (free(str), 1) && !get_next_line(-1))
				check_error_type(line);
			free(str);
			str = get_next_line(*fd);
		}
		return (1);
	}
	return (0);
}

void	read_map(t_map *map_info, int fd)
{
	char	*line;
	char	*str;
	bool	flag;

	line = ft_strdup("");
	flag = false;
	str = get_next_line(fd);
	while (str)
	{
		if (!flag && check_map_content(str))
			flag = true;
		if (check_map_newline(str, flag, &fd, line))
			break ;
		if (!is_newline(str))
			line = ft_strjoin_2(line, str);
		free(str);
		str = get_next_line(fd);
	}
	if (!(*line))
		ft_exit1("Error Map Empty!\n", line);
	map_info->arr = ft_split(line, '\n');
	free(line);
}
