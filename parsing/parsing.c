/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:36:01 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/11/19 23:54:42 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void remove_whitspaces (t_map *map_info)
{
    int i;
    i = -1;
    int j;
    while (++i < 6)
    {
        j = -1;
        while(map_info->arr[i][++j])
        {
            if (map_info->arr[i][j] != ' ' && map_info->arr[i][j] != '\t')
            {
                map_info->arr[i] = map_info->arr[i] + j;
                break;
            }
        }
    }
}
void   check_map_infos_components (char **arr)
{
    int j;
    int i;
    i = 0;
    while (arr[i])
    { 
        j = 0 ;
        while (arr[i][j])
        {
            if (find_component(arr[i][j]) && compare_tool(arr[i]))
                ft_exit("Error: wrong arguments in map\n");
            j++;
        }
        i++;
    }
}

void check_isvalid_mapinfo(t_map *map_info)
{
    check_textures_colors (map_info->arr);
    check_xmp_textures(map_info->arr);
    check_rgb_colors(map_info->arr, "C "); 
    check_rgb_colors(map_info->arr, "F ");
}
void check_isvalid_map (t_map *map_info)
{
    check_is_OnePlayer(map_info->arr + 6, map_info);
    check_map_is_closed(map_info->arr + 6);   
}

void parsing (t_map *map_info, char *filename)
{
    int len;
    len = ft_strlen(filename) - 4;
    if (ft_strncmp(filename + len, ".cub", 4))
        ft_exit("filename must end with .cub\n");
    
    read_map(map_info, filename);
    remove_whitspaces(map_info);
    check_map_infos_components(map_info->arr); // components check
    check_isvalid_mapinfo(map_info); //textures and colors
    check_isvalid_map(map_info); // map
    return ;
}
