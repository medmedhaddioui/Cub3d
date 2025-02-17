/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:09:12 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/10 22:21:12 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx_data->addr + (y * mlx_data->line_length + x
			* (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mini_map_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH * 1 / 5 || y < 0 || y >= HEIGHT * 1 / 5)
		return ;
	dst = mlx_data->addr + (y * mlx_data->line_length + x
			* (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_img(t_data *data, int width, int height)
{
	int	line;
	int	col;

	line = 0;
	while (line < height)
	{
		col = 0;
		while (col < width)
		{
			my_mlx_pixel_put(data->mlx_struct, col, line, BLACK);
			col++;
		}
		line++;
	}
}

void	free_memory(t_data *data)
{
	int		i;
	t_map	*map;

	i = 0;
	map = data->map;
	while (map->arr[i])
		free(map->arr[i++]);
	free(map->arr);
	i = 0;
	while (i < map->height)
		free(map->map2d[i++]);
	free(map->map2d);
	free(data->anim_tex);
	free(data->mlx_struct->mlx);
	free(data->mlx_struct);
	free(data->player);
	free(data->ray);
	free(map);
	exit(EXIT_SUCCESS);
}

void	free_tex(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_struct->mlx, data->close_door_tex.img);
	mlx_destroy_image(data->mlx_struct->mlx, data->open_door_tex.img);
	mlx_destroy_image(data->mlx_struct->mlx, data->no_tex.img);
	mlx_destroy_image(data->mlx_struct->mlx, data->so_tex.img);
	mlx_destroy_image(data->mlx_struct->mlx, data->ea_tex.img);
	mlx_destroy_image(data->mlx_struct->mlx, data->we_tex.img);
	while (i < FRAME_NUMBER)
	{
		mlx_destroy_image(data->mlx_struct->mlx, data->anim_tex[i].img);
		i++;
	}
}
