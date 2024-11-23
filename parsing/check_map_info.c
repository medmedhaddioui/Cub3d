/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:43:51 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/11/22 16:06:41 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void init_data (t_program *data)
{
    data->i = 0;
    data->no_texture = 0;
    data->so_texture = 0;
    data->we_texture = 0;
    data->ea_texture = 0;
    data->floor = 0;
    data->ceiling = 0;
}

void check_textures_colors(char **arr)
{
    t_program data;
    init_data(&data);
    int flag = 0;
    while (data.i < 6)
    {
        if (!ft_strncmp(arr[data.i], "NO ", 3))
            data.no_texture++;
        else if (!ft_strncmp(arr[data.i], "SO ", 3))
            data.so_texture++;
        else if (!ft_strncmp(arr[data.i], "WE ", 3))
            data.we_texture++;
        else if (!ft_strncmp(arr[data.i], "EA ", 3))
            data.ea_texture++;
        else if (!ft_strncmp(arr[data.i], "F ", 2))
            data.floor++;
        else if (!ft_strncmp(arr[data.i], "C ", 2))
            data.ceiling++;
        else
            flag ++;
        data.i++;
    }
    if (data.no_texture != 1 || data.so_texture != 1 || data.we_texture != 1 || data.ea_texture != 1 ||  
        data.floor != 1 || data.ceiling != 1 || !compare_tool(arr[data.i]))
        ft_exit("Missing or duplicated texture or RGB colors\n");
    if (flag)
        ft_exit("Map before/mid info map !!\n");
}

void check_rgb_value (char *value, char type)
{
    int i;
    i = -1;
    while (value[++i])
    {
        if (!ft_isdigit(value[i]) &&  value[i] != ' ' && value[i] != '\t')
            ft_error(type);
    }
    if (modified_ft_atoi(value) == -1)
        ft_error(type);
}

void count_comma (char *s, char type)
{
    int n;
    n = 0;
    if (!s)
        ft_error(type);
    while (*s)
    {
        if (*s == ',')
            n++;
        s++;
    }
    if (n != 2)
        ft_error(type);
}

int merge_colors(char **arr)
{
    
    return((ft_atoi(arr[0]) << 16 ) + (ft_atoi(arr[1]) << 8 ) + ft_atoi(arr[2])); 
}
void check_rgb_colors( char **arr, char *s, int *color)
{
    int i;
    i = 0;
    char **tmp;
    while (arr[i] && ft_strncmp(arr[i], s, 2))
        i++;
    count_comma(arr[i], *s);
    if (arr [i] && arr[i][0] == *s && arr[i][1] == ' ')
    {
        tmp = ft_split(&arr[i][2], ',');
        i = -1;
        while (tmp[++i])
            check_rgb_value(tmp[i], *s);
        if (i != 3)
            ft_error(*s);
        *color = merge_colors(tmp);
    }
}

void check_is_xmp(char *path)
{
    int len;

    len = ft_strlen(path) - 4;
    if (path[len - 1] == ' ')
        ft_exit("Filename must end with .xpm\n");
    
    if (ft_strcmp(path + len, ".xpm"))
        ft_exit("Filename must end with .xpm !\n");
}

void check_xmp_textures(char **arr)
{
    int i;
    i = -1;
    while (++i < 6)
    {
        if (!ft_strncmp(arr[i], "NO ", 3) || !ft_strncmp(arr[i], "SO ", 3) || 
            !ft_strncmp(arr[i], "WE ", 3) || !ft_strncmp(arr[i], "EA ", 3))
                check_is_xmp(arr[i]);
    }
}
