/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:20:42 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/03 18:29:16 by mel-hadd         ###   ########.fr       */
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
    if (!ft_strncmp(str + i, "NO", 2)|| !ft_strncmp(str + i, "SO", 2) || 
        !ft_strncmp(str + i, "WE", 2) || !ft_strncmp(str + i, "EA", 2) || 
        !ft_strncmp(str + i, "F", 1) || !ft_strncmp(str + i, "C", 1))
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
    if (fd < 0)
        ft_exit("Error in Mapfile\n");
    while ((str = get_next_line(fd)))
    {
        if (check_map_content(str) && flag == 0)
            flag = 1;
        if (flag == 1 && str[0] != '\n')
            flag = 2;
        if (flag == 2 && is_newline(str))
        {
            
            while ((str = get_next_line(fd)))
            {
                if (!is_newline(str))
                    ft_exit("Error newline in map\n");
            }
            break;
        }
        line = ft_strjoin(line, str);
        free(str);
    }
    if (!(*line))
        ft_exit("Error map Empty!\n");
    map_info->arr = ft_split(line, '\n');
}

void parsing (t_map *map_info, char *filename)
{
    read_map(map_info, filename);
    return ;
}

