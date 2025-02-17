/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:55:24 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/12/26 20:12:53 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	put_info(int *dest_int, char *src_char, int width)
{
	int	i;

	i = 0;
	while (src_char[i])
	{
		if (src_char[i] == '\t' || src_char[i] == ' ')
			dest_int[i] = 1;
		else if (src_char[i] == 'N' || src_char[i] == 'S' || src_char[i] == 'W'
			|| src_char[i] == 'E')
			dest_int[i] = 0;
		else if (src_char[i] == 'D')
			dest_int[i] = 2;
		else
			dest_int[i] = src_char[i] - '0';
		i++;
	}
	while (i < width)
		dest_int[i++] = 1;
}

char	*find_direction(char **arr, char *direction)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] && i < MAP_INFO)
	{
		if (!ft_strncmp(arr[i], direction, 3))
		{
			j = 2;
			while (arr[i][j] && (arr[i][j] == ' ' || arr[i][j] == '\t'))
				j++;
			return (arr[i] + j);
		}
		i++;
	}
	return (NULL);
}

void	setup_rest(t_map *map_info, char **str)
{
	char	**tmp;
	char	*s;
	int		i;
	int		j;

	tmp = malloc(sizeof(char *) * 4);
	i = -1;
	while (++i < 4)
	{
		s = find_direction(map_info->arr, str[i]);
		tmp[i] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		ft_memcpy(tmp[i], s, (ft_strlen(s) + 1));
	}
	i = 0;
	j = 0;
	while (i < MAP_INFO)
	{
		free(map_info->arr[i]);
		map_info->arr[i] = NULL;
		if (i < 4)
			map_info->arr[i] = tmp[j++];
		i++;
	}
	free(tmp);
}

void	setup_map(t_map *map_info)
{
	int		i;
	int		j;
	char	*str[4];

	str[0] = "NO ";
	str[1] = "SO ";
	str[2] = "EA ";
	str[3] = "WE ";
	i = 6;
	j = 0;
	map_info->map2d = malloc(sizeof(int *) * map_info->height);
	while (map_info->arr[i])
	{
		map_info->map2d[j] = malloc(sizeof(int) * map_info->width);
		put_info(map_info->map2d[j++], map_info->arr[i], map_info->width);
		free(map_info->arr[i]);
		map_info->arr[i++] = NULL;
	}
	setup_rest(map_info, str);
}
