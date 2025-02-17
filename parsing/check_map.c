/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:43:05 by mel-hadd          #+#    #+#             */
/*   Updated: 2025/01/14 18:51:40 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_pos(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != 'D')
		return (1);
	return (0);
}

void	check_element_iswall(char **arr, int height, int width, t_map *map)
{
	if (height - 1 < 0 || width - 1 < 0 || height + 1 > map->height
		|| width + 1 > map->width)
		ft_exit ("Error map not closed !\n", map->arr);
	if (check_pos(arr[height - 1][width]) || check_pos(arr[height + 1][width])
		|| check_pos(arr[height][width + 1]) || check_pos(arr[height][width
			- 1]))
		ft_exit("Error Map not closed !!\n", map->arr);
}

void	check_doorwalls(char **arr, int height, int width, t_map *map)
{
	if (arr[height][width + 1] != '1' || arr[height][width - 1] != '1')
	{
		if (arr[height + 1][width] != '1' || arr[height - 1][width] != '1')
			ft_exit("Erron in door\n", map->arr);
	}
}

void	check_last_line(char **arr, int i, t_map *map)
{
	int	j;

	j = 0;
	while (arr[i][j] && (arr[i][j] == '1' || arr[i][j] == ' '
			|| arr[i][j] == '\t'))
		j++;
	if (arr[i][j])
		ft_exit("Error Map not Closed!!\n", map->arr);
}

void	check_map_is_closed(char **arr, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (arr[0][j] && (arr[0][j] == '1' || arr[0][j] == ' '
			|| arr[0][j] == '\t'))
		j++;
	if (arr[0][j])
		ft_exit("Error Map not Closed!!\n", map->arr);
	i = 1;
	while (arr[i])
	{
		j = -1;
		if (!arr[i + 1])
			break ;
		while (arr[i][++j])
		{
			if (arr[i][j] != '1' && arr[i][j] != ' ' && arr[i][j] != '\t')
				check_element_iswall(arr, i, j, map);
			if (arr[i][j] == 'D')
				check_doorwalls(arr, i, j, map);
		}
		i++;
	}
	check_last_line(arr, i, map);
}
