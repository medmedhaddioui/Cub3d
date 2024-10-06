/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:21:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/06 14:00:57 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_exit (char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}


void ft_error (char type)
{
    if (type == 'F')
        ft_putstr_fd("Error in Floor RGB colors !!\n", 2);
    else
        ft_putstr_fd("Error in Ceiling RGB colors !!\n", 2);
    exit(1);
}


void print_map (t_map map_info)
{
    for (int i= 0; map_info.arr[i];i++)
        printf("%s\n",map_info.arr[i]);

    printf("\n-- VALID MAP -- \n");
}