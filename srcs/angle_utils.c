/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forrest <forrest@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:08:17 by forrest           #+#    #+#             */
/*   Updated: 2024/12/14 23:12:30 by forrest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	valid_angle(double angle)
{
	if (angle >= 0 && angle < 2 * PI)
		return (angle);
	if (angle > 0)
	{
		while (angle >= 2 * PI)
			angle -= 2 * PI;
		return (angle);
	}
	else if (angle < 0)
	{
		while (angle < 0)
			angle += 2 * PI;
		return (angle);
	}
	return (0);
}

bool	ray_facing_up(double angle)
{
	if (angle > PI && angle < 2 * PI)
		return (true);
	else
		return (false);
}

bool	ray_facing_down(double angle)
{
	return (!ray_facing_up(angle));
}

bool	ray_facing_left(double angle)
{
	if (angle > PI / 2 && angle < 3 * PI / 2)
		return (true);
	else
		return (false);
}

bool	ray_facing_right(double angle)
{
	return (!ray_facing_left(angle));
}
