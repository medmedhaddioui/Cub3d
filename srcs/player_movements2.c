/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:04:33 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/01 15:27:39 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	is_a_wall(t_data *data, double x, double y)
{
	int	point_x;
	int	point_y;

	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return (true);
	point_x = (int)floor(x / (double)data->tile_width);
	point_y = (int)floor(y / (double)data->tile_height);
	if ((data->map->map2d)[point_y][point_x] == 1)
		return (true);
	else
		return (false);
}

void	player_traslation(int key, t_data *data, t_player *player)
{
	if (key == W)
		up_key(player, data);
	else if (key == S)
		down_key(player, data);
	else if (key == A)
		left_key(player, data);
	else if (key == D)
		right_key(player, data);
}

void	player_rotation(int key, t_player *player)
{
	if (key == RIGHT)
		player->rotation_angle += 5 * PI / 180;
	else if (key == LEFT)
		player->rotation_angle -= 5 * PI / 180;
}

int	move_player(int key, t_data *data)
{
	if (!(key == W || key == S || key == D || key == A
			|| key == RIGHT || key == LEFT))
		return (0);
	player_traslation(key, data, data->player);
	player_rotation(key, data->player);
	return (0);
}
