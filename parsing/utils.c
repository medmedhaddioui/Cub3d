/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:21:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/09 18:54:46 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void ft_exit (char *str)
{
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void ft_error (char type)
{
    if (type == 'F')
        ft_putstr_fd("Floor RGB colors !!\n", 2);
    else
        ft_putstr_fd("Ceiling RGB colors !!\n", 2);
    exit(EXIT_FAILURE);
}

int	modified_ft_atoi(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)) 
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		return -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
        if (result > 250)
            return -1;
		nptr++;
	}
	return (result);
}

void print_map (t_map map_info)
{
    for (int i= 0; map_info.arr[i];i++)
        printf("%s\n",map_info.arr[i]);

    printf("\n-- VALID MAP -- \n");
}
