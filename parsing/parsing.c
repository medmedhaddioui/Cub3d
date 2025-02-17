/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:36:01 by mel-hadd          #+#    #+#             */
/*   Updated: 2025/01/02 22:04:44 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	remove_whitspaces(t_map *map_info)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str;
	size_t	len;

	i = 0;
	while (map_info->arr[i] && i < MAP_INFO)
	{
		j = -1;
		while (map_info->arr[i][++j])
		{
			if (map_info->arr[i][j] != ' ' && map_info->arr[i][j] != '\t')
			{
				tmp = map_info->arr[i];
				str = map_info->arr[i] + j;
				len = ft_strlen(str) + 1;
				map_info->arr[i] = malloc(sizeof(char) * len);
				ft_memcpy(map_info->arr[i], str, len);
				free(tmp);
				break ;
			}
		}
		i++;
	}
}

void	check_map_infos_components(char **arr)
{
	int	j;
	int	i;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (find_component(arr[i][j]) && compare_tool(arr[i]))
				ft_exit("Error: wrong arguments in map\n", arr);
			j++;
		}
		i++;
	}
}

void	check_isvalid_mapinfo(t_map *map_info)
{
	check_textures_colors(map_info->arr);
	check_xmp_textures(map_info->arr);
	check_rgb_colors(map_info->arr, "C ", &map_info->ceiling_color);
	check_rgb_colors(map_info->arr, "F ", &map_info->floor_color);
}

void	check_isvalid_map(t_map *map_info)
{
	check_is_oneplayer(map_info->arr + MAP_INFO, map_info);
	check_map_is_closed(map_info->arr + MAP_INFO, map_info);
}

void	parsing(t_map *map_info, char *filename)
{
	int	fd;

	open_and_check_file(filename, &fd);
	read_map(map_info, fd);
	remove_whitspaces(map_info);
	check_map_infos_components(map_info->arr);
	check_isvalid_mapinfo(map_info);
	get_height_width_map(map_info);
	check_isvalid_map(map_info);
	get_direction(map_info);
	setup_map(map_info);
	check_existing_textures(map_info);
	return ;
}
