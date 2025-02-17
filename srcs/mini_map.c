/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:28:30 by forrest           #+#    #+#             */
/*   Updated: 2025/01/01 20:54:55 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	render_player(t_data *data)
{
	int		i;
	double	angle;
	t_point	point1;
	t_point	point2;

	point1.x = WIDTH * 1 / 10;
	point1.y = HEIGHT * 1 / 10;
	i = 0;
	angle = data->player->rotation_angle - data->fov / 2;
	while (i < 50)
	{
		point2.x = WIDTH * 1 / 10 + 35 * cos(angle);
		point2.y = HEIGHT * 1 / 10 + 35 * sin(angle);
		draw_line(&point1, &point2, data->mlx_struct);
		angle += data->fov / 50;
		i++;
	}
}

void	mini_square(t_data *data, int x, int y, int color)
{
	int	line;
	int	col;
	int	width;
	int	height;

	line = 0;
	width = data->tile_width * data->zoom_fact;
	height = data->tile_height * data->zoom_fact;
	while (line < height)
	{
		col = 0;
		while (col < width)
		{
			mini_map_pixel_put(data->mlx_struct, x + col, y + line, color);
			col++;
		}
		line++;
	}
}

int	zoom_x(t_data *data, int x)
{
	t_player	*player;

	player = data->player;
	return ((x * data->tile_width - player->x) * data->zoom_fact
		+ WIDTH * 1 / 10);
}

int	zoom_y(t_data *data, int y)
{
	t_player	*player;

	player = data->player;
	return ((y * data->tile_height - player->y) * data->zoom_fact
		+ HEIGHT * 1 / 10);
}

void	render_map(t_data *data, int **map)
{
	int	y;
	int	x;

	y = 0;
	reset_img(data, WIDTH * 1 / 5, HEIGHT * 1 / 5);
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (map[y][x] == 0)
				mini_square(data, zoom_x(data, x), zoom_y(data, y), WHITE);
			else if (map[y][x] == 2)
				mini_square(data, zoom_x(data, x), zoom_y(data, y), DOOR_COLOR);
			else
				mini_square(data, zoom_x(data, x), zoom_y(data, y), 0x000000FF);
			x++;
		}
		y++;
	}
}
