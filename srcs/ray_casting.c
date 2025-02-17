/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:09:11 by forrest           #+#    #+#             */
/*   Updated: 2025/01/01 21:02:18 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	ray_blocked(t_data *data, double x, double y)
{
	int	point_x;
	int	point_y;

	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return (true);
	point_x = (int)floor(x / (double)data->tile_width);
	point_y = (int)floor(y / (double)data->tile_height);
	if ((data->map->map2d)[point_y][point_x] == 1)
		return (true);
	else if ((data->map->map2d)[point_y][point_x] == 2)
		return (true);
	else
		return (false);
}

void	horizontal_casting(t_data *data, t_ray *ray)
{
	ray->deltay = data->tile_height;
	ray->deltax = ray->deltay / tan(ray->angle);
	if (ray_facing_up(ray->angle) && ray->deltay > 0)
		ray->deltay *= -1;
	if (ray_facing_down(ray->angle) && ray->deltay < 0)
		ray->deltay *= -1;
	if (ray_facing_left(ray->angle) && ray->deltax > 0)
		ray->deltax *= -1;
	if (ray_facing_right(ray->angle) && ray->deltax < 0)
		ray->deltax *= -1;
	ray->x_horz = ray->xintercept;
	ray->y_horz = ray->yintercept;
	while (ray->x_horz >= 0 && ray->x_horz < data->map_width
		&& ray->y_horz >= 0 && ray->y_horz < data->map_height)
	{
		ray->increment = 0;
		if (ray_facing_up(ray->angle))
			ray->increment = 1;
		if (ray_blocked(data, ray->x_horz, ray->y_horz - ray->increment))
			break ;
		ray->x_horz += ray->deltax;
		ray->y_horz += ray->deltay;
	}
}

void	vertical_casting(t_data *data, t_ray *ray)
{
	ray->deltax = data->tile_width;
	ray->deltay = ray->deltax * tan(ray->angle);
	if (ray_facing_up(ray->angle) && ray->deltay > 0)
		ray->deltay *= -1;
	if (ray_facing_down(ray->angle) && ray->deltay < 0)
		ray->deltay *= -1;
	if (ray_facing_left(ray->angle) && ray->deltax > 0)
		ray->deltax *= -1;
	if (ray_facing_right(ray->angle) && ray->deltax < 0)
		ray->deltax *= -1;
	ray->x_vert = ray->xintercept;
	ray->y_vert = ray->yintercept;
	while (ray->x_vert >= 0 && ray->x_vert < data->map_width
		&& ray->y_vert >= 0 && ray->y_vert < data->map_height)
	{
		ray->increment = 0;
		if (ray_facing_left(ray->angle))
			ray->increment = 1;
		if (ray_blocked(data, ray->x_vert - ray->increment, ray->y_vert))
			break ;
		ray->x_vert += ray->deltax;
		ray->y_vert += ray->deltay;
	}
}

void	cast_ray(t_data *data, t_ray *ray)
{
	t_player	*player;

	player = data->player;
	ray->yintercept = (int)player->y / data->tile_height * data->tile_height;
	if (ray_facing_down(ray->angle))
		ray->yintercept += data->tile_height;
	ray->xintercept = (int)player->x + (ray->yintercept - (int)player->y)
		/ tan(ray->angle);
	horizontal_casting(data, ray);
	ray->xintercept = (int)player->x / data->tile_width * data->tile_width;
	if (ray_facing_right(ray->angle))
		ray->xintercept += data->tile_width;
	ray->yintercept = (int)player->y + (ray->xintercept - (int)player->x)
		* tan(ray->angle);
	vertical_casting(data, ray);
	calcul_distance(data, ray);
	check_door_hit(data, ray);
}

void	cast_rays(t_data *data)
{
	int		i;
	double	increment_angle;
	double	player_angle;
	t_ray	*ray;

	i = 0;
	ray = data->ray;
	increment_angle = data->fov / WIDTH;
	player_angle = data->player->rotation_angle;
	while (i < WIDTH)
	{
		ray->ray_index = i;
		ray->hit_door = false;
		ray->angle = valid_angle(player_angle - data->fov / 2
				+ i * increment_angle);
		cast_ray(data, ray++);
		i++;
	}
}

// int	render_ray(t_data *data, t_ray *ray)
// {
// 	t_player	*ply;

// 	ply = data->player;
// 	if (distance(ply, ray->x_horz, ray->y_horz)
// 		> distance(ply, ray->x_vert, ray->y_vert))
// 	{
// 		if (!(ray->x_vert >= 0 && ray->x_vert < WIDTH
// 				&& ray->y_vert >= 0 && ray->y_vert < HEIGHT))
// 			return (printf("vertical  %f, %f\n", ray->x_vert, ray->y_vert));
// 		ray->ray_distance = distance(ply, ray->x_vert, ray->y_vert);
// 		draw_line(
// 			ply->x * SCALE_FACT, ply->y * SCALE_FACT, ray->x_vert * SCALE_FACT,
// 			ray->y_vert * SCALE_FACT, data->mlx_struct, 0x00FF00);
// 	}
// 	else
// 	{
// 		if (!(ray->x_horz >= 0 && ray->x_horz < WIDTH
// 				&& ray->y_horz >= 0 && ray->y_horz < HEIGHT))
// 			return (printf("horizontal  %f, %f\n", ray->x_horz, ray->y_horz));
// 		ray->ray_distance = distance(ply, ray->x_horz, ray->y_horz);
// 		draw_line(
// 			ply->x * SCALE_FACT, ply->y * SCALE_FACT, ray->x_horz * SCALE_FACT,
// 			ray->y_horz * SCALE_FACT, data->mlx_struct, 0x00FF00);
// 	}
// 	return (0);
// }

// void	render_rays(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		render_ray(data, data->ray + i);
// 		i++;
// 	}
// }
