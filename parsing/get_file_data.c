/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:32:16 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/09 19:50:49 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


int is_newline(char *s)
{
    int i;
    i = 0;
    while (s[i] && s[i] == ' ') // skip space then check is_newline
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
    if (!compare_tool(str + i))
        return 0;
    return 1;
}
void check_error_type(char *line)
{
    char **tmp_arr = ft_split(line, '\n');
    int i;
    i = 0;
    int j;
    int flag = 0 ;
    while (tmp_arr[i])
    { 
        j = 0 ;
        while (tmp_arr[i][j] && tmp_arr[i][j] == ' ')
            j++;
        if (compare_tool(&tmp_arr[i][j]))
            flag = 1;
        else if (flag && !compare_tool(&tmp_arr[i][j]))
            ft_exit("Map before/mid info map\n");
        i++;
    }
    ft_exit("Error Newline in map !\n");
}
int  check_map_newline(char *str, bool flag, int *fd, char *line)
{
    if (flag == true && is_newline(str))
    {
        while ((str = get_next_line(*fd)))
        {
            line = ft_strjoin (line, str);
            if (!is_newline(str))
                check_error_type(line);
            free(str);
        }
        return 1;
    }
    return 0;
}

void read_map(t_map *map_info, char *filename)
{
    int fd;
    char *line;
    char *str;
    bool flag;
    
    line = ft_strdup("");
    fd = open(filename, O_RDONLY, 0666);
    if (fd == -1)
        ft_exit("Error in Filemap\n");
    while ((str = get_next_line(fd)))
    {
        if (!flag && check_map_content(str))
            flag = true;
        if (check_map_newline(str, flag , &fd, line))
            break;
        if (is_newline(str))
            continue;
        line = ft_strjoin(line, str);
        free(str);
    }
    if (!(*line))
        ft_exit("Map Empty!\n");
    map_info->arr = ft_split(line, '\n');
}
