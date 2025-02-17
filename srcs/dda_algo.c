/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:00 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/01 17:54:41 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

unsigned int	get_color(t_mlx *mlx_data, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH * 1 / 5 || y < 0 || y >= HEIGHT * 1 / 5)
		return (0);
	dst = mlx_data->addr + (y * mlx_data->line_length + x
			* (mlx_data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_line(t_point *p1, t_point *p2, t_mlx *mlx_data)
{
	t_dda	vars;
	int		i;

	vars.dx = p2->x - p1->x;
	vars.dy = p2->y - p1->y;
	vars.steps = ft_abs(vars.dy);
	if (ft_abs(vars.dx) > ft_abs(vars.dy))
		vars.steps = ft_abs(vars.dx);
	vars.xinc = vars.dx / (float) vars.steps;
	vars.yinc = vars.dy / (float) vars.steps;
	vars.x = p1->x;
	vars.y = p1->y;
	my_mlx_pixel_put(mlx_data, vars.x, vars.y, RED);
	i = 0;
	while (i < vars.steps)
	{
		vars.x += vars.xinc;
		vars.y += vars.yinc;
		if (get_color(mlx_data, vars.x, vars.y) == WALL_COLOR
			|| get_color(mlx_data, vars.x, vars.y) == DOOR_COLOR)
			break ;
		my_mlx_pixel_put(mlx_data, vars.x, vars.y,
			point_color(RED, WHITE, vars.steps, i++));
		i++;
	}
}

// void	draw_line(int x1, int y1, int x2, int y2, t_mlx *mlx_data)
// {
// 	t_dda	vars;
// 	int		i;
// 	float	x;
// 	float	y;

// 	vars.dx = x2 - x1;
// 	vars.dy = y2 - y1;
// 	vars.steps = ft_abs(vars.dy);
// 	if (ft_abs(vars.dx) > ft_abs(vars.dy))
// 		vars.steps = ft_abs(vars.dx);
// 	vars.xinc = vars.dx / (float) vars.steps;
// 	vars.yinc = vars.dy / (float) vars.steps;
// 	x = x1;
// 	y = y1;
// 	my_mlx_pixel_put(mlx_data, x1, y1, 0x0000FF);
// 	i = 0;
// 	while (i < vars.steps)
// 	{
// 		x += vars.xinc;
// 		y += vars.yinc;
// 		if (get_color(mlx_data, x, y) == 0x0000FF)
// 			break ;
// 		my_mlx_pixel_put(mlx_data, x, y,
// 			point_color(0xFF0000, 0xFFFFFF, vars.steps, i++));
// 		i++;
// 	}
// }
