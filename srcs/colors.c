/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:35:40 by noudrib           #+#    #+#             */
/*   Updated: 2024/12/21 23:25:14 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	point_color(int color1, int color2, int x2, int x)
{
	int		color;
	int		red;
	int		gr;
	int		bl;
	float	per;

	per = (float)ft_abs(x - 0) / (float)ft_abs(0 - x2);
	red = (1 - per) * get_r(color1) + (per) * get_r(color2);
	gr = (1 - per) * get_g(color1) + (per) * get_g(color2);
	bl = (1 - per) * get_b(color1) + (per) * get_b(color2);
	color = create_trgb(0, red, gr, bl);
	return (color);
}
