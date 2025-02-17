/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:59:28 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/11 19:12:32 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (data->mouse_x - x > 0)
		data->player->rotation_angle -= 1 * PI / 180;
	else if (data->mouse_x - x < 0)
		data->player->rotation_angle += 1 * PI / 180;
	else
		return (0);
	if (data->mouse_flag == 0)
		data->mouse_x = x;
	else if (data->mouse_flag == 1)
	{
		data->mouse_x = WIDTH / 2;
		mlx_mouse_move(data->mlx_struct->mlx,
			data->mlx_struct->window, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}

int	enter_win(t_data *data)
{
	mlx_mouse_hide(data->mlx_struct->mlx, data->mlx_struct->window);
	data->mouse_flag = 1;
	return (0);
}

void	mlx_hooks(t_data *data)
{
	t_mlx	*mlx_struct;

	mlx_struct = data->mlx_struct;
	mlx_hook(mlx_struct->window, 2, 1L << 0, keyboard_event, data);
	mlx_hook(mlx_struct->window, 6, 1L << 6, mouse_move, data);
	mlx_hook(mlx_struct->window, 7, 1L << 4, enter_win, data);
	mlx_hook(mlx_struct->window, 17, 0, close_win_mouse, data);
	mlx_loop_hook(data->mlx_struct->mlx, render, data);
}
