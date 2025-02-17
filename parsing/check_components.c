/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:41:11 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/12/26 17:21:37 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	find_component(char c)
{
	if (c != ' ' && c != '\t' && c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E' && c != 'D')
		return (1);
	return (0);
}

int	compare_tool(char *s)
{
	if (!ft_strncmp(s, "NO ", 3) || !ft_strncmp(s, "SO ", 3) || !ft_strncmp(s,
			"WE ", 3) || !ft_strncmp(s, "EA ", 3) || !ft_strncmp(s, "F ", 2)
		|| !ft_strncmp(s, "C ", 2))
		return (0);
	return (1);
}

int	get_index_player(int y, int x, t_map *map)
{
	map->y_player = y;
	map->x_player = x;
	return (1);
}

void	check_is_oneplayer(char **arr, t_map *map_info)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	if (!arr[i])
		ft_exit("Error missing map !\n", map_info->arr);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (find_component(arr[i][j]))
				ft_exit("Error wrong component in map\n", map_info->arr);
			else if ((arr[i][j] == 'N' || arr[i][j] == 'S' || arr[i][j] == 'W'
					|| arr[i][j] == 'E') && get_index_player(i, j, map_info))
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_exit("Error A single player must be on the map.!\n", map_info->arr);
}
