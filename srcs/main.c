/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:20:39 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/14 19:27:51 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	player_init(t_data *data)
{
	data->tile_width = data->no_tex.tex_width;
	data->tile_height = data->no_tex.tex_height;
	data->map_width = data->tile_width * data->map->width;
	data->map_height = data->tile_height * data->map->height;
	data->player->x = data->tile_width * data->map->x_player
		+ data->tile_width / 2;
	data->player->y = data->tile_height * data->map->y_player
		+ data->tile_height / 2;
	data->fov = (60 * PI) / 180;
	data->player->walking_step = data->tile_width / 10;
	data->player->wall_check_step = data->tile_width / 4;
	data->zoom_fact = 15 / (double)data->tile_width;
	if (data->map->direction_player == 'N')
		data->player->rotation_angle = 3 * PI / 2;
	else if (data->map->direction_player == 'S')
		data->player->rotation_angle = PI / 2;
	else if (data->map->direction_player == 'E')
		data->player->rotation_angle = 0;
	else if (data->map->direction_player == 'W')
		data->player->rotation_angle = PI;
}

void	render_animation(t_data *data, int frame_index)
{
	t_tex			*tex;
	int				x;
	int				y;
	unsigned int	pixel_color;

	y = 0;
	tex = data->anim_tex + frame_index;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_color = *(unsigned int *)(tex->img_addr
					+ y * tex->tex_height / HEIGHT * tex->tex_line_length
					+ x * tex->tex_width / WIDTH * (tex->tex_bpp / 8));
			if (pixel_color != 0xff000000)
				my_mlx_pixel_put(data->mlx_struct, x, y, pixel_color);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	t_mlx		*s_mlx;
	static int	i;

	if (i / 5 >= FRAME_NUMBER)
		i = 0;
	s_mlx = data->mlx_struct;
	cast_rays(data);
	render_walls(data);
	render_map(data, data->map->map2d);
	render_player(data);
	render_animation(data, i / 5);
	mlx_put_image_to_window(s_mlx->mlx, s_mlx->window, s_mlx->img, 0, 0);
	i++;
	return (0);
}

void	inite_data(t_data *data, t_map map)
{
	data->mlx_struct = (t_mlx *)malloc(sizeof(t_mlx));
	data->player = (t_player *)malloc(sizeof(t_player));
	data->ray = (t_ray *)malloc(sizeof(t_ray) * WIDTH);
	data->anim_tex = (t_tex *)malloc(sizeof(t_tex) * FRAME_NUMBER);
	data->map = (t_map *)malloc(sizeof(t_map));
	*(data->map) = map;
	data->mouse_x = WIDTH / 2;
	data->mouse_flag = 1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		printf("please entre the map of the maze\n");
		exit(1);
	}
	parsing (&map, argv[1]);
	inite_data(&data, map);
	data.mlx_struct->mlx = mlx_init();
	data.mlx_struct->window = mlx_new_window(data.mlx_struct->mlx,
			WIDTH, HEIGHT, "cub3D");
	data.mlx_struct->img = mlx_new_image(data.mlx_struct->mlx, WIDTH, HEIGHT);
	data.mlx_struct->addr = mlx_get_data_addr(data.mlx_struct->img,
			&data.mlx_struct->bits_per_pixel,
			&data.mlx_struct->line_length, &data.mlx_struct->endian);
	init_wall_tex(&data);
	init_door_tex(&data);
	init_anim_tex(&data);
	player_init(&data);
	mlx_hooks(&data);
	mlx_loop(data.mlx_struct->mlx);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	if (argc != 2)
// 	{
// 		printf("please entre the map of the maze\n");
// 		exit(1);
// 	}
// 	inite_data(&data);
// 	parsing (data.map, argv[1]);
// 	data.mlx_struct->mlx = mlx_init();
// 	data.mlx_struct->window = mlx_new_window(data.mlx_struct->mlx,
// 			WIDTH, HEIGHT, "cub3D");
// 	data.mlx_struct->img = mlx_new_image(data.mlx_struct->mlx, WIDTH, HEIGHT);
// 	data.mlx_struct->addr = mlx_get_data_addr(data.mlx_struct->img,
// 			&data.mlx_struct->bits_per_pixel,
// 			&data.mlx_struct->line_length, &data.mlx_struct->endian);
// 	init_tex(&data);
// 	player_init(&data);
// 	render(&data);
// 	mlx_hook(data.mlx_struct->window, 2, 1L << 0, keyboard_event, &data);
// 	mlx_hook(data.mlx_struct->window, 6, 1L << 6, mouse_move, &data);
// 	mlx_hook(data.mlx_struct->window, 7, 1L << 4, enter_win, &data);
// 	mlx_hook(data.mlx_struct->window, 17, 0, close_win_mouse, data.mlx_struct);
// 	mlx_loop_hook(data.mlx_struct->mlx, render, &data);
// 	mlx_loop(data.mlx_struct->mlx);
// 	return (0);
// }

// void	render_square(t_data *data, int x, int y, int width, int height,
// int color)
// {
// 	int	line;
// 	int	col;
// 	line = 0;
// 	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
// 	{
// 		printf("xff = %d\n", x);
// 		printf("yff = %d\n", y);
// 		return ;
// 	}
// 	while (line < height)
// 	{
// 		col = 0;
// 		while (col < width)
// 		{
// 			my_mlx_pixel_put(data->mlx_struct, x + col, y + line, color);
// 			col++;
// 		}
// 		line++;
// 	}
// }
