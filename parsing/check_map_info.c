/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:43:51 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/12/26 17:27:53 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_data(t_program *data)
{
	data->i = 0;
	data->no_texture = 0;
	data->so_texture = 0;
	data->we_texture = 0;
	data->ea_texture = 0;
	data->floor = 0;
	data->ceiling = 0;
}

void	check_textures_colors(char **arr)
{
	t_program	data;

	init_data(&data);
	while (arr[data.i] && data.i < MAP_INFO)
	{
		if (!ft_strncmp(arr[data.i], "NO ", 3))
			data.no_texture++;
		else if (!ft_strncmp(arr[data.i], "SO ", 3))
			data.so_texture++;
		else if (!ft_strncmp(arr[data.i], "WE ", 3))
			data.we_texture++;
		else if (!ft_strncmp(arr[data.i], "EA ", 3))
			data.ea_texture++;
		else if (!ft_strncmp(arr[data.i], "F ", 2))
			data.floor++;
		else if (!ft_strncmp(arr[data.i], "C ", 2))
			data.ceiling++;
		data.i++;
	}
	if (data.no_texture != 1 || data.so_texture != 1 || data.we_texture != 1
		|| data.ea_texture != 1 || data.floor != 1 || data.ceiling != 1)
		ft_exit("Error Missing or duplicated texture or RGB colors\n", arr);
}

void	check_is_xmp(char *path, char **arr)
{
	int		len;
	char	**tmp_arr;
	int		i;

	len = ft_strlen(path) - 4;
	if (path[len - 1] == ' ' || path[len - 1] == '\t')
		ft_exit("Erron in Filename .xpm\n", arr);
	if (ft_strcmp(path + len, ".xpm"))
		ft_exit("Error Filename must end with .xpm !\n", arr);
	tmp_arr = ft_split(path, ' ');
	i = 0;
	while (tmp_arr[i])
		i++;
	free_arr(tmp_arr);
	if (i != 2)
		ft_exit("Error in texture file\n", arr);
}

void	check_xmp_textures(char **arr)
{
	int	i;

	i = -1;
	while (++i < MAP_INFO)
	{
		if (!ft_strncmp(arr[i], "NO ", 3) || !ft_strncmp(arr[i], "SO ", 3)
			|| !ft_strncmp(arr[i], "WE ", 3) || !ft_strncmp(arr[i], "EA ", 3))
			check_is_xmp(arr[i], arr);
	}
}
