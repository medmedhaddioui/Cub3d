#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
// #include <mlx.h>

typedef struct s_program
{
    int i;
    int no_texture;
    int so_texture;
    int we_texture;
    int ea_texture;
    int floor;
    int ceiling;
} t_program;

typedef struct s_map
{
    char **arr;
    int y_player;
    int x_player;
    int height;
    int width;
    int floor_color;
    int cellling_color;

}t_map;

//parsing
void ft_exit (char *str);
void parsing (t_map *map_info, char *filename);
void check_isvalid_map (t_map *map_info);
void check_isvalid_mapinfo(t_map *map_info);
void check_map_infos_components(char **arr);
void check_xmp_textures(char **arr);
void check_rgb_colors( char **arr, char *s);
void check_textures_colors(char **arr);
void check_map_is_closed(char **arr);
void read_map(t_map *map_info, char *filename);
int  compare_tool (char *s);
int	modified_ft_atoi(const char *nptr);
void check_is_OnePlayer(char **arr, t_map *map_info);
int find_component(char c);
//errors
void ft_error (char type);

// tmp 
void print_map (t_map map_info);

#endif