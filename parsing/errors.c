/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:43:44 by mel-hadd          #+#    #+#             */
/*   Updated: 2025/01/14 18:53:58 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_exit1(char *err, char *s)
{
	free(s);
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str, char **arr)
{
	ft_putstr_fd(str, 2);
	free_arr(arr);
	exit(EXIT_FAILURE);
}

void	ft_error(char type, char **arr)
{
	if (type == 'F')
		ft_putstr_fd("Error in Floor RGB colors !!\n", 2);
	else
		ft_putstr_fd("Error in Ceiling RGB colors !!\n", 2);
	free_arr(arr);
	exit(EXIT_FAILURE);
}

void	end(t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[i])
		free(map->arr[i++]);
	free(map->arr);
	i = 0;
	while (i < map->height)
		free(map->map2d[i++]);
	free(map->map2d);
	ft_putstr_fd("Error in xpm path\n", 2);
	exit(EXIT_FAILURE);
}

void	check_existing_textures(t_map *map)
{
	int			i;
	int			fd;
	const char	*doors[] = {OPEN_DOOR, CLOSED_DOOR, NULL};

	i = 0;
	while (map->arr[i])
	{
		fd = open(map->arr[i], O_RDONLY);
		if (fd == -1)
			end(map);
		close (fd);
		i++;
	}
	i = -1;
	while (doors[++i])
	{
		fd = open (doors[i], O_RDONLY);
		if (fd == -1)
			end(map);
		close (fd);
	}
}
