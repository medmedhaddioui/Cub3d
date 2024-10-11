/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:51:56 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/10/11 12:46:15 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
        }
    }
}
void get_height_width_map(t_map *map)
{
    int y = 0;
    size_t max = 0;
    char **arr = map->arr + 6;
    while (arr[y])
    {
        if (max < ft_strlen(arr[y]))
            max = ft_strlen(arr[y]);
        y++;
    }
    map->height = y;
    map->width = max;
    printf("%d\n",map->height);
    printf("%d\n",map->width);
}
void set_map(t_map *map)
{
    void	*mlx;
	void	*mlx_win;
    get_height_width_map(map);
	mlx = mlx_init(map);
	mlx_win = mlx_new_window(mlx, (map->width * 32),(map->height * 32) , "Cub3D");
    draw_square(mlx, mlx_win,  (map->width_player *32),(map->height_player * 32) ,  32, 0x0000FF00);
	mlx_loop(mlx);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 1;
    t_map map_info;
    parsing (&map_info, av[1]);
    set_map(&map_info);
    print_map(map_info);
    return 0;
}