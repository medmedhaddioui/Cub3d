/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:41:11 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/09 19:38:52 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int find_component(char c)
{
    if (c != ' ' && c != '\t' && c != '0' && c != '1'
        && c != 'N' && c != 'S' && c != 'W' && c != 'E')
            return 1;
    return 0;
}
int  compare_tool (char *s)
{
    if (!ft_strncmp(s, "NO ", 3)|| !ft_strncmp(s, "SO ", 3) || 
        !ft_strncmp(s, "WE ", 3) || !ft_strncmp(s, "EA ", 3) || 
        !ft_strncmp(s, "F ", 2) || !ft_strncmp(s, "C ", 2))
            return 0;
    return 1;
}

void check_is_OnePlayer(char **arr)
{
    int i;
    i = 0;
    int j;
    int player = 0;
    while (arr[i])
    {
        j = 0;
        while (arr[i][j])
        {
            if (arr[i][j] == 'N' || arr[i][j] == 'S' ||arr[i][j] == 'W' || arr[i][j] == 'E')
                player++;
            j++;
        }
        i++;
    }
    if (player != 1)
        ft_exit("A single player must be on the map.!\n");
}