/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:43:05 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/08 17:04:48 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


int check_pos (char c)
{

    if (c != '0' && c != '1'
        && c != 'N' && c != 'S' && c != 'W' && c != 'E')
        return 1;
    return 0;
}
void check_Element_iswall(char **arr, int height, int width)
{
    if (check_pos(arr[height - 1][width]) || check_pos(arr[height + 1][width]) ||
        check_pos(arr[height][width + 1]) || check_pos(arr[height][width - 1]))
        ft_exit("Map not closed wst\n");
}
void check_map_is_closed(char **arr)
{
    int i;
    int j;
    j = 0;
    while (arr[0][j] && (arr[0][j] == '1' || arr[0][j] == ' ' || arr[0][j] == '\t'))
        j++;
    if (arr[0][j])
        ft_exit("Map not Closed!!\n");
    i = 1;
    while (arr[i])
    {
        if (!arr[i + 1])
            break;
        j = -1;
        while (arr[i][++j])
        {
            if (arr[i][j] != '1' && arr[i][j] != ' ' && arr[i][j] != '\t')
                check_Element_iswall(arr, i, j);
        }
        i++;
    }
    j = 0;
    while (arr[i][j] && (arr[i][j] == '1' || arr[i][j] == ' ' || arr[i][j] == '\t'))
        j++;
    if (arr[i][j])
        ft_exit("Map not Closed!!\n");
}