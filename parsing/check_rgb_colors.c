/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rbg_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:27:06 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/12/26 17:28:08 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_rgb_value(char *value)
{
	int		i;
	bool	flag;

	i = 0;
	while (value[i] && (value[i] == ' ' || value[i] == '\t'))
		i++;
	if (!value[i])
		return (1);
	flag = false;
	while (value[i])
	{
		if (!ft_isdigit(value[i]) && value[i] != ' ' && value[i] != '\t')
			return (1);
		else if (!ft_isdigit(value[i]))
			flag = true;
		else if (ft_isdigit(value[i]) && flag)
			return (1);
		i++;
	}
	if (modified_ft_atoi(value) == -1)
		return (1);
	return (0);
}

void	count_comma(char *s, char type, char **arr)
{
	int	comma_nb;

	comma_nb = 0;
	if (!s)
		ft_error(type, arr);
	while (*s)
	{
		if (*s == ',')
			comma_nb++;
		s++;
	}
	if (comma_nb != 2)
		ft_error(type, arr);
}

int	merge_colors(char **arr)
{
	return ((ft_atoi(arr[0]) << 16) + (ft_atoi(arr[1]) << 8) + ft_atoi(arr[2]));
}

void	check_rgb_colors(char **arr, char *s, int *color)
{
	int		i;
	char	**tmp;
	bool	flag;

	i = 0;
	flag = false;
	while (arr[i] && ft_strncmp(arr[i], s, 2))
		i++;
	count_comma(arr[i], *s, arr);
	if (arr[i] && arr[i][0] == *s && arr[i][1] == ' ')
	{
		tmp = ft_split(&arr[i][2], ',');
		i = -1;
		while (tmp[++i] && !flag)
			flag = check_rgb_value(tmp[i]);
		if (flag && (free_arr(tmp), 1))
			ft_error(*s, arr);
		if (i != 3 && (free_arr(tmp), 1))
			ft_error(*s, arr);
		*color = merge_colors(tmp);
		free_arr(tmp);
	}
	else
		ft_error(*s, arr);
}
