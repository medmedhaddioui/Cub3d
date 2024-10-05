/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:20:42 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/05 21:12:30 by mel-hadd         ###   ########.fr       */
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
int  compare_tool (char *s)
{
    if (!ft_strncmp(s, "NO ", 3)|| !ft_strncmp(s, "SO ", 3) || 
        !ft_strncmp(s, "WE ", 3) || !ft_strncmp(s, "EA ", 3) || 
        !ft_strncmp(s, "F ", 2) || !ft_strncmp(s, "C ", 2))
            return 0;
    return 1;
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
int  check_map_newline(char *str, int *flag, int *fd)
{
    if (is_newline(str) && *flag == 2)
    {
        while ((str = get_next_line(*fd)))
        {
            if (!is_newline(str))
                ft_exit("Error newline in map content\n");
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
        if (check_map_newline(str, &flag , &fd))
            break;
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
            ft_exit("Error map before/mid info map\n"); // go other func check what is the content
        i++;
    }
    if (no_texture != 1 ||  so_texture != 1 ||  we_texture != 1 ||  ea_texture != 1 ||  
            floor != 1 ||  ceiling != 1)
        ft_exit("Error missing or duplicated texture or RGB colors\n");
}

int	modified_ft_atoi(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		return -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
        if (result > 250)
            return -1;
		nptr++;
	}
	return (result);
}
void check_rgb_value (char *value)
{
    if (modified_ft_atoi(value) == -1)
        ft_exit("Error in RGB colors !");
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
            check_rgb_value(tmp[i]);
        if (i != 3)
            ft_exit("Error in RGB colors missing!");
    }
}
// int  ft_strcmp(char *s1, char *s2)
// {
//     if (!s1 || !s2)
//         return 0;
//     while (*s1 && *s2 && *s1 == *s2)
//     {
//         s1++;
//         s2++;
//     }
//     if (*s1 == *s2)
//         return 0;
//     return 1;
// }
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
void check_is_xmp(char *path)
{
    int len;

    len = ft_strlen(path) - 4;
    if (path[len - 1] == ' ')
        ft_exit("Error: filename must end with .xpm\n");
    if (path[len] != '.' || path[len + 1] != 'x' 
        || path[len + 2] != 'p'|| path[len + 3] != 'm')
    {
        printf("%c\n",path[len + 2]);
        ft_exit("Error: filename must end with .xpm\n");
    }
}

void check_xmp_textures(char **arr)
{
    int i;
    i = -1;
    while (++i < 6)
    {
        if (!ft_strncmp(arr[i], "NO ", 3) || !ft_strncmp(arr[i], "SO ", 3) ||
            !ft_strncmp(arr[i], "WE ", 3) || !ft_strncmp(arr[i], "EA ", 3))
                check_is_xmp(arr[i]); // problem here (ft_strcmp)
    }
}
void check_isvalid_mapinfo(t_map *map_info)
{
    check_textures_colors (map_info->arr);
    check_xmp_textures(map_info->arr);
    check_rgb_colors(map_info->arr, "C "); 
    check_rgb_colors(map_info->arr, "F ");
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
void   check_map_components (char **arr)
{
    int i;
    i = -1;
    while (++i < 6)
    {
        if (compare_tool(arr[i]))
            ft_exit("Error wrong arguments in map_info");         
    }
    int j;
    while (arr[i])
    {
        j = 0 ;
        while (arr[i][j])
        {
            if (arr [i][j] != ' ' && arr [i][j] != '\t' &&arr [i][j] != '0' && arr [i][j] != '1' && 
                arr [i][j] != 'N' && arr [i][j] != 'S' && arr [i][j] != 'W' && 
                     arr [i][j] != 'E')
                ft_exit("Error wrong arguments in map_content");           
            j++;
        }
        i++;
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
    check_map_components (map_info->arr);
    // check_isvalid_mapcontent(map_info);
    check_isvalid_mapinfo(map_info);
    return ;
}

