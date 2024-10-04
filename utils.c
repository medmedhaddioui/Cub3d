/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:21:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/04 21:52:02 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_exit (char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}

void print_map (t_map map_info)
{
    for (int i= 0; map_info.arr[i];i++)
        printf("%s\n",map_info.arr[i]);

    printf("\n-- VALID MAP -- \n");
}