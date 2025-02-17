/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:21:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2025/01/14 18:50:40 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	modified_ft_atoi(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		return (-1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result > 255)
			return (-1);
		nptr++;
	}
	return (result);
}

void	get_height_width_map(t_map *map)
{
	int		y;
	size_t	max;
	char	**arr;

	y = 0;
	max = 0;
	arr = map->arr + MAP_INFO;
	while (arr[y])
	{
		if (max < ft_strlen(arr[y]))
			max = ft_strlen(arr[y]);
		y++;
	}
	map->height = y;
	map->width = max;
}

void	get_direction(t_map *map)
{
	map->direction_player = map->arr[map->y_player + MAP_INFO][map->x_player];
}

void	open_and_check_file(char *filename, int *fd)
{
	int	len;

	len = ft_strlen(filename) - 4;
	if (len > 4 && ft_strncmp(filename + len, ".cub", 4))
	{
		ft_putstr_fd("Error filename must end with .cub\n", 2);
		exit(EXIT_FAILURE);
	}
	*fd = open(filename, O_RDONLY, 0666);
	if (*fd == -1)
	{
		ft_putstr_fd("Error in fd !\n", 2);
		exit(EXIT_FAILURE);
	}
}

// void	print_map(t_map map_info)
// {
// 	for (int i = 0; map_info.arr[i]; i++)
// 		printf("%s\n", map_info.arr[i]);
// 	printf("\n-- VALID MAP INFO-- \n");
// 	for (int i = 0; i < map_info.height; i++)
// 	{
// 		for (int j = 0; j < map_info.width; j++)
// 			printf("%d", map_info.map2d[i][j]);
// 		printf("\n");
// 	}
// 	printf("-- VALID MAP -- \n");
// 	printf("--->%c\n", map_info.direction_player);
// }