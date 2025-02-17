/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:54:03 by forrest           #+#    #+#             */
/*   Updated: 2025/01/10 20:46:53 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_anim_tex(t_data *data)
{
	int			i;
	const char	*path[FRAME_NUMBER] = {"player/4.xpm", "player/5.xpm",
		"player/6.xpm", "player/7.xpm", "player/8.xpm", "player/9.xpm",
		"player/10.xpm", "player/11.xpm", "player/12.xpm", "player/13.xpm",
		"player/14.xpm", "player/15.xpm", "player/16.xpm", "player/17.xpm",
		"player/18.xpm", "player/19.xpm", "player/20.xpm", "player/21.xpm",
		"player/22.xpm", "player/23.xpm", "player/24.xpm", "player/25.xpm",
		"player/26.xpm", "player/27.xpm", "player/28.xpm", "player/29.xpm",
		"player/30.xpm", "player/31.xpm", "player/32.xpm", "player/33.xpm",
		"player/38.xpm", "player/34.xpm", "player/35.xpm", "player/36.xpm",
		"player/37.xpm", "player/39.xpm", "player/40.xpm"
	};

	i = 0;
	while (i < FRAME_NUMBER)
	{
		data->anim_tex[i].img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
				(char *)path[i], &data->anim_tex[i].tex_width,
				&data->anim_tex[i].tex_height);
		data->anim_tex[i].img_addr = mlx_get_data_addr(data->anim_tex[i].img,
				&data->anim_tex[i].tex_bpp, &data->anim_tex[i].tex_line_length,
				&data->anim_tex[i].tex_endian);
		i++;
	}
}

void	init_door_tex(t_data *data)
{
	data->close_door_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			CLOSED_DOOR, &data->close_door_tex.tex_width,
			&data->close_door_tex.tex_height);
	data->close_door_tex.img_addr = mlx_get_data_addr(data->close_door_tex.img,
			&data->close_door_tex.tex_bpp,
			&data->close_door_tex.tex_line_length,
			&data->close_door_tex.tex_endian);
	data->open_door_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			OPEN_DOOR, &data->open_door_tex.tex_width,
			&data->open_door_tex.tex_height);
	data->open_door_tex.img_addr = mlx_get_data_addr(data->open_door_tex.img,
			&data->open_door_tex.tex_bpp, &data->open_door_tex.tex_line_length,
			&data->open_door_tex.tex_endian);
}

void	init_wall_tex(t_data *data)
{
	data->no_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			(data->map->arr)[0], &data->no_tex.tex_width,
			&data->no_tex.tex_height);
	data->no_tex.img_addr = mlx_get_data_addr(data->no_tex.img,
			&data->no_tex.tex_bpp, &data->no_tex.tex_line_length,
			&data->no_tex.tex_endian);
	data->so_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			(data->map->arr)[1], &data->so_tex.tex_width,
			&data->so_tex.tex_height);
	data->so_tex.img_addr = mlx_get_data_addr(data->so_tex.img,
			&data->so_tex.tex_bpp, &data->so_tex.tex_line_length,
			&data->so_tex.tex_endian);
	data->ea_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			(data->map->arr)[2], &data->ea_tex.tex_width,
			&data->ea_tex.tex_height);
	data->ea_tex.img_addr = mlx_get_data_addr(data->ea_tex.img,
			&data->ea_tex.tex_bpp, &data->ea_tex.tex_line_length,
			&data->ea_tex.tex_endian);
	data->we_tex.img = mlx_xpm_file_to_image(data->mlx_struct->mlx,
			(data->map->arr)[3], &data->we_tex.tex_width,
			&data->we_tex.tex_height);
	data->we_tex.img_addr = mlx_get_data_addr(data->we_tex.img,
			&data->we_tex.tex_bpp, &data->we_tex.tex_line_length,
			&data->we_tex.tex_endian);
}

t_tex	*select_tex(t_data *data, t_ray *ray)
{
	if (ray->hit_door == 2)
		return (&data->open_door_tex);
	if (ray->hit_door == 1)
		return (&data->close_door_tex);
	if (ray_facing_up(ray->angle) && ray->hit_vertical == false)
		return (&data->no_tex);
	if (ray_facing_down(ray->angle) && ray->hit_vertical == false)
		return (&data->so_tex);
	if (ray_facing_left(ray->angle) && ray->hit_vertical == true)
		return (&data->we_tex);
	if (ray_facing_right(ray->angle) && ray->hit_vertical == true)
		return (&data->ea_tex);
	return (NULL);
}

// int		get_tex_color(t_data *data, t_ray *ray, int offsetY, int offsetX)
// {
// 	if (isFacingUp(ray->angle) && ray->rayHitVertical == false)
// 		return (*(int*)(data->NO_tex.img_addr + offsetY
// * data->NO_tex.tex_line_length + offsetX * (data->NO_tex.tex_bpp / 8)));
// 	if (isFacingDown(ray->angle) && ray->rayHitVertical == false)
// 		return (*(int*)(data->SO_tex.img_addr + offsetY
// * data->SO_tex.tex_line_length + offsetX * (data->SO_tex.tex_bpp / 8)));
// 	if (isFacingLeft(ray->angle) && ray->rayHitVertical == true)
// 		return (*(int*)(data->WE_tex.img_addr + offsetY
// * data->WE_tex.tex_line_length + offsetX * (data->WE_tex.tex_bpp / 8)));
// 	if (isFacingRight(ray->angle) && ray->rayHitVertical == true)
// 		return (*(int*)(data->EA_tex.img_addr + offsetY
// * data->EA_tex.tex_line_length + offsetX * (data->EA_tex.tex_bpp / 8)));
// 	return (0);
// }