/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:33:57 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/10 20:51:43 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	close_win_mouse(t_data *data)
{
	t_mlx	*mlx_struct;

	mlx_struct = data->mlx_struct;
	free_tex(data);
	mlx_destroy_image(mlx_struct->mlx, mlx_struct->img);
	mlx_destroy_window(mlx_struct->mlx, mlx_struct->window);
	mlx_destroy_display(mlx_struct->mlx);
	free_memory(data);
	exit(0);
}

int	close_win_keyboard(int key, t_data *data)
{
	t_mlx	*mlx_struct;

	mlx_struct = data->mlx_struct;
	if (key == ESC)
	{
		free_tex(data);
		mlx_destroy_image(mlx_struct->mlx, mlx_struct->img);
		mlx_destroy_window(mlx_struct->mlx, mlx_struct->window);
		mlx_destroy_display(mlx_struct->mlx);
		free_memory(data);
		exit(0);
	}
	return (0);
}

int	zoom_map(int key, t_data *data)
{
	if (key == PLUS)
		data->zoom_fact += 0.01;
	else if (key == MINUS && data->zoom_fact - 0.01 > 0.01)
		data->zoom_fact -= 0.01;
	else
		return (0);
	return (0);
}

int	keyboard_event(int key, t_data *data)
{
	if (key == P)
	{
		mlx_mouse_show(data->mlx_struct->mlx, data->mlx_struct->window);
		data->mouse_flag = 0;
		return (0);
	}
	move_player(key, data);
	zoom_map(key, data);
	close_win_keyboard(key, data);
	return (0);
}
