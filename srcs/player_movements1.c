/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:36:44 by forrest           #+#    #+#             */
/*   Updated: 2024/12/21 23:45:08 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	up_key(t_player *player, t_data *data)
{
	double	x;
	double	y;

	x = player->x;
	y = player->y;
	x += (player->walking_step * cos(player->rotation_angle));
	if (!is_a_wall(data,
			x + player->wall_check_step * cos(player->rotation_angle), y))
		player->x = x;
	y += (player->walking_step * sin(player->rotation_angle));
	if (!is_a_wall(data, player->x,
			y + player->wall_check_step * sin(player->rotation_angle)))
		player->y = y;
}

void	down_key(t_player *player, t_data *data)
{
	double	x;
	double	y;

	x = player->x;
	y = player->y;
	x -= (player->walking_step * cos(player->rotation_angle));
	if (!is_a_wall(data,
			x - player->wall_check_step * cos(player->rotation_angle), y))
		player->x = x;
	y -= (player->walking_step * sin(player->rotation_angle));
	if (!is_a_wall(data, player->x,
			y - player->wall_check_step * sin(player->rotation_angle)))
		player->y = y;
}

void	right_key(t_player *player, t_data *data)
{
	double	x;
	double	y;

	x = player->x;
	y = player->y;
	x -= (player->walking_step * sin(player->rotation_angle));
	if (!is_a_wall(data,
			x - player->wall_check_step * sin(player->rotation_angle), y))
		player->x = x;
	y += (player->walking_step * cos(player->rotation_angle));
	if (!is_a_wall(data, player->x,
			y + player->wall_check_step * cos(player->rotation_angle)))
		player->y = y;
}

void	left_key(t_player *player, t_data *data)
{
	double	x;
	double	y;

	x = player->x;
	y = player->y;
	x += (player->walking_step * sin(player->rotation_angle));
	if (!is_a_wall(data,
			x + player->wall_check_step * sin(player->rotation_angle), y))
		player->x = x;
	y -= (player->walking_step * cos(player->rotation_angle));
	if (!is_a_wall(data, player->x,
			y - player->wall_check_step * cos(player->rotation_angle)))
		player->y = y;
}

// void	player_traslation(int key, t_player	*player, double *x, double *y)
// {
// 	if (key == W)
// 	{
// 		*x += (10 * cos(player->rotation_angle));
// 		*y += (10 * sin(player->rotation_angle));
// 	}
// 	else if (key == S)
// 	{
// 		*x -= (10 * cos(player->rotation_angle));
// 		*y -= (10 * sin(player->rotation_angle));
// 	}
// 	else if (key == A)
// 	{
// 		*x += (10 * sin(player->rotation_angle));
// 		*y -= (10 * cos(player->rotation_angle));
// 	}
// 	else if (key == D)
// 	{
// 		*x -= (10 * sin(player->rotation_angle));
// 		*y += (10 * cos(player->rotation_angle));
// 	}
// }

// int	move_player(int key, t_data *data)
// {
// 	double		x;
// 	double		y;

// 	x = data->player->x;
// 	y = data->player->y;
// 	if (!(key == W || key == S || key == D || key == A
// 			|| key == RIGHT || key == LEFT))
// 		return (0);
// 	player_traslation(key, data->player, &x, &y);
// 	player_rotation(key, data->player);
// 	if (is_a_wall(data, x, y) == false)
// 	{
// 		data->player->x = x;
// 		data->player->y = y;
// 	}
// 	else
// 		wall_collision(key, data);
// 	render(data);
// 	return (0);
// }
