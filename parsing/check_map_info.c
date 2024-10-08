/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:43:51 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/08 12:56:39 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void check_textures_colors(char **arr)
{
    int no_texture;
    int so_texture;
    int we_texture;
    int ea_texture;
    int floor;
    int ceiling;
    int i;

    
    i = 0;
    no_texture = 0;
    so_texture = 0;
    we_texture = 0;
    ea_texture = 0;
    floor = 0;
    ceiling = 0;
   
    while (i < 6)
    {
        if (!ft_strncmp(arr[i], "NO ", 3))
            no_texture++;
        else if (!ft_strncmp(arr[i], "SO ", 3))
            so_texture++;
        else if (!ft_strncmp(arr[i], "WE ", 3))
            we_texture++;
        else if (!ft_strncmp(arr[i], "EA ", 3))
            ea_texture++;
        else if (!ft_strncmp(arr[i], "F ", 2))
            floor++;
        else if (!ft_strncmp(arr[i], "C ", 2))
            ceiling++;
        else
            ft_exit("Map before/mid info map\n"); // go other func check what is the content
        i++;
    }
    if (no_texture != 1 ||  so_texture != 1 ||  we_texture != 1 ||  ea_texture != 1 ||  
            floor != 1 ||  ceiling != 1)
        ft_exit("Missing or duplicated texture or RGB colors\n");
}

void check_rgb_value (char *value, char type)
{
    if (modified_ft_atoi(value) == -1)
        ft_error(type);
}


void check_rgb_colors( char **arr, char *s)
{
    int i;
    i = 0;
    char **tmp;
    while (arr[i] && ft_strncmp(arr[i], s, 2))
        i++;
    if (arr [i] && arr[i][0] == *s && arr[i][1] == ' ')
    {
        tmp = ft_split(&arr[i][2], ',');
        i = -1;
        while (tmp[++i])
            check_rgb_value(tmp[i], *s);
        if (i != 3)
            ft_error(*s);
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


