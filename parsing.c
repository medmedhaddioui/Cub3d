/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:20:42 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/04 22:19:01 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int is_newline(char *s)
{
    int i;
    i = 0;
    while (s[i] && s[i] == ' ')
        i++;
    if (s[i] == '\n')
        return 1;
    return 0;
}

int check_map_content(char *str)
{
    int i;
    i = 0;
    if (is_newline(str))
        return 0;
    while (str[i] && str[i] == ' ')
        i++;
    if (!str[i])
        return 0;
    if (!ft_strncmp(str + i, "NO ", 3)|| !ft_strncmp(str + i, "SO ", 3) || 
        !ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "EA ", 3) || 
        !ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "C ", 2))
            return 0;
    return 1;
}

void read_map(t_map *map_info, char *filename)
{
    int fd;
    char *line;
    char *str;
    int flag;
    
    flag = 0;
    line = ft_strdup("");
    fd = open(filename, O_RDONLY, 0666);
    if (fd == -1)
        ft_exit("Error in Mapfile\n");
    while ((str = get_next_line(fd)))
    {
        if (check_map_content(str) && flag == 0)
            flag = 1;
        if (str[0] != '\n' && flag == 1)
            flag = 2;
        if (is_newline(str) && flag == 2)
        {
            while ((str = get_next_line(fd)))
            {
                if (!is_newline(str))
                    ft_exit("Error newline in map\n");
            }
            break;
        }
        if (is_newline(str))
            continue;
        line = ft_strjoin(line, str);
        free(str);
    }
    if (!(*line))
        ft_exit("Error map Empty!\n");
    map_info->arr = ft_split(line, '\n');
}

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
   
    while (arr[i])
    {
        if (!ft_strncmp(arr[i], "NO ", 3))
            no_texture++;
        if (!ft_strncmp(arr[i], "SO ", 3))
            so_texture++;
        if (!ft_strncmp(arr[i], "WE ", 3))
            we_texture++;
        if (!ft_strncmp(arr[i], "EA ", 3))
            ea_texture++;
        if (!ft_strncmp(arr[i], "F ", 2))
            floor++;
        if (!ft_strncmp(arr[i], "C ", 2))
            ceiling++;
        i++;
    }
    if (no_texture != 1 ||  so_texture != 1 ||  we_texture != 1 ||  ea_texture != 1 ||  
            floor != 1 ||  ceiling != 1)
        ft_exit("Error missing or duplicated texture or colors\n");
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
        i = 0;
        while (tmp[i])
            i++;
        if (i != 3)
            ft_exit("Error in RGB colors !");
    }
}
void check_isvalid_mapinfo(char **arr)
{
    check_textures_colors (arr);
    // check_xmp_textures(arr);
    check_rgb_colors(arr, "C "); 
    check_rgb_colors(arr, "F ");
}

void parse_map (t_map *map_info)
{
    int i;
    i = -1;
    int j;
    while (++i < 6)
    {
        j = 0;
        while(map_info->arr[i][j])
        {
            if (map_info->arr[i][j] == ' ' || map_info->arr[i][j] == '\t')
                j++;
            else
            {
                map_info->arr[i] = map_info->arr[i] + j;
                break;
            }
        }
    }
}

void parsing (t_map *map_info, char *filename)
{
    int len;
    len = ft_strlen(filename) - 4;
    if (ft_strncmp(filename + len, ".cub", 4))
        ft_exit("Error filename must end with .cub\n");
    
    read_map(map_info, filename);
    parse_map(map_info);
    check_isvalid_mapinfo(map_info->arr);
    return ;
}

