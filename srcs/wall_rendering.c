/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:38:44 by forrest           #+#    #+#             */
/*   Updated: 2025/01/01 20:55:26 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_offset_x(t_data *data, t_ray *ray)
{
	int		offset_x;
	t_tex	*tex;

	tex = select_tex(data, ray);
	if (ray->hit_vertical == false)
		offset_x = (ray->wallx % data->tile_width) * tex->tex_width
			/ data->tile_width;
	else
		offset_x = (ray->wally % data->tile_height) * tex->tex_width
			/ data->tile_height;
	return (offset_x);
}

void	render_wall_strip(t_data *data, t_ray *ray, int wall_bottom_pixel,
	int wall_top_pixel)
{
	int		y;
	int		offset_y;
	int		tex_color;
	int		max_y;
	t_tex	*tex;

	max_y = wall_bottom_pixel;
	tex = select_tex(data, ray);
	y = wall_top_pixel;
	if (y < 0)
		y = 0;
	if (max_y >= HEIGHT)
		max_y = HEIGHT;
	while (y < max_y)
	{
		offset_y = (y - wall_top_pixel) * tex->tex_height / ray->wall_height;
		tex_color = *(int *)(tex->img_addr + offset_y * tex->tex_line_length
				+ get_offset_x(data, ray) * (tex->tex_bpp / 8));
		my_mlx_pixel_put(data->mlx_struct, ray->ray_index, y, tex_color);
		y++;
	}
}

void	render_wall(t_data *data, t_ray *ray)
{
	double	distance_proj_plan;
	int		bottom_pixel;
	int		top_pixel;
	int		i;

	distance_proj_plan = (WIDTH / 2) / tan(data->fov / 2);
	ray->wall_height = data->tile_height * distance_proj_plan
		/ (ray->ray_distance * cos (data->player->rotation_angle - ray->angle));
	top_pixel = (HEIGHT - ray->wall_height) / 2;
	bottom_pixel = (HEIGHT - ray->wall_height) / 2 + ray->wall_height;
	i = 0;
	while (i < top_pixel)
		my_mlx_pixel_put(data->mlx_struct, ray->ray_index, i++,
			data->map->ceiling_color);
	render_wall_strip(data, ray, bottom_pixel, top_pixel);
	i = bottom_pixel;
	while (i < HEIGHT)
		my_mlx_pixel_put(data->mlx_struct, ray->ray_index, i++,
			data->map->floor_color);
}

void	render_walls(t_data *data)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		render_wall(data, data->ray + i);
		i++;
	}
}
