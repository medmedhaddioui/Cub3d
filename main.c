/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:51:56 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/11/23 22:24:14 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



int main (int ac, char **av)
{
    if (ac != 2)
        return 1;
    t_map map_info;
    parsing (&map_info, av[1]);
    print_map(map_info);
    return 0;
}