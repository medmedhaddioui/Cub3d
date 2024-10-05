#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct s_program
{
    int x;
    int i;
    
} t_program;


typedef struct s_map
{
    char **arr;

}t_map;

//parsing
void ft_exit (char *str);
void parsing (t_map *map_info, char *filename);
int compare_tool (char *s);

// tmp 
void print_map (t_map map_info);

#endif