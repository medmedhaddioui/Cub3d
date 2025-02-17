/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:54:02 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/01 20:34:34 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	distance(t_player *player, double x, double y)
{
	double	distance;

	distance = sqrt((player->x - x) * (player->x - x)
			+ (player->y - y) * (player->y - y));
	return (distance);
}

bool	is_door(t_data *data, t_ray *ray, double x, double y)
{
	int	point_x;
	int	point_y;

	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return (true);
	point_x = (int)floor(x / (double)data->tile_width);
	point_y = (int)floor(y / (double)data->tile_height);
	if ((data->map->map2d)[point_y][point_x] == 2)
	{
		if (ray->ray_distance < (double)data->tile_width * 1.5)
			ray->hit_door = 2;
		else
			return (true);
	}
	return (false);
}
// bool	is_door(t_data *data, double x, double y)
// {
// 	int	point_x;
// 	int	point_y;

// 	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
// 		return (true);
// 	point_x = (int)floor(x / (double)data->tile_width);
// 	point_y = (int)floor(y / (double)data->tile_height);
// 	if ((data->map->map2d)[point_y][point_x] == 2)
// 		return (true);
// 	else
// 		return (false);
// }

void	check_door_hit(t_data *data, t_ray *ray)
{
	if (ray->hit_vertical)
	{
		ray->increment = 0;
		if (ray_facing_left(ray->angle))
			ray->increment = 1;
		if (is_door(data, ray, ray->wallx - ray->increment, ray->wally) == true)
			ray->hit_door = true;
	}
	else
	{
		ray->increment = 0;
		if (ray_facing_up(ray->angle))
			ray->increment = 1;
		if (is_door(data, ray, ray->wallx, ray->wally - ray->increment) == true)
			ray->hit_door = true;
	}
}

int	calcul_distance(t_data *data, t_ray *ray)
{
	if (distance(data->player, ray->x_horz, ray->y_horz)
		> distance(data->player, ray->x_vert, ray->y_vert))
	{
		if (!(ray->x_vert >= 0 && ray->x_vert < data->map_width
				&& ray->y_vert >= 0 && ray->y_vert < data->map_height))
			return (printf("vert  %f, %f\n", ray->x_vert, ray->y_vert));
		ray->wallx = ray->x_vert;
		ray->wally = ray->y_vert;
		ray->hit_vertical = true;
		ray->ray_distance = distance(data->player, ray->x_vert, ray->y_vert);
	}
	else
	{
		if (!(ray->x_horz >= 0 && ray->x_horz < data->map_width
				&& ray->y_horz >= 0 && ray->y_horz < data->map_height))
			return (printf("horz %f, %f\n", ray->x_horz, ray->y_horz));
		ray->wallx = ray->x_horz;
		ray->wally = ray->y_horz;
		ray->hit_vertical = false;
		ray->ray_distance = distance(data->player, ray->x_horz, ray->y_horz);
	}
	return (0);
}
