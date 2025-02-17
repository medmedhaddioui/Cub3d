/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:47:41 by noudrib           #+#    #+#             */
/*   Updated: 2025/01/14 18:55:35 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/Inc/libft.h"
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# define ZOOM_FACT 2
# define WIDTH 1200
# define HEIGHT 1000
# define PI 3.141592653589793
# define WALL_CHECK 20
# define A 97
# define D 100
# define S 115
# define W 119
# define P 112
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define PLUS 65451
# define MINUS 65453
# define STEP 10
# define WALL_COLOR 0x0000FF
# define DOOR_COLOR 0x00964B00
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define BLACK 0x000000
# define FRAME_NUMBER 37
# define CLOSED_DOOR "./textures/door/doors_1.xpm"
# define OPEN_DOOR "./textures/door/doors_2.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_player
{
	double	x;
	double	y;
	double	direction_x;
	double	direction_y;
	double	rotation_angle;
	int		walking_step;
	int		wall_check_step;
}				t_player;

typedef struct s_ray
{
	int			ray_index;
	double		angle;
	double		xintercept;
	double		yintercept;
	double		x_horz;
	double		y_horz;
	double		x_vert;
	double		y_vert;
	double		deltax;
	double		deltay;
	double		ray_distance;
	double		wall_height;
	int			increment;
	int			wallx;
	int			wally;
	int			hit_door;
	bool		hit_vertical;
}				t_ray;

typedef struct s_tex
{
	void	*img;
	char	*img_addr;
	int		tex_bpp;
	int		tex_line_length;
	int		tex_endian;
	int		tex_width;
	int		tex_height;
}				t_tex;

typedef struct s_map
{
	char	**arr; // information map NO SO EA WE
	int		**map2d; // map
	int		y_player;
	int		x_player;
	char	direction_player;
	int		height;
	int		width;
	int		floor_color;
	int		ceiling_color;
}			t_map; // data of program

typedef struct s_data
{
	t_mlx		*mlx_struct;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	int			tile_width;
	int			tile_height;
	int			map_width;
	int			map_height;
	t_tex		no_tex;
	t_tex		so_tex;
	t_tex		ea_tex;
	t_tex		we_tex;
	t_tex		close_door_tex;
	t_tex		open_door_tex;
	t_tex		*anim_tex;
	double		zoom_fact;
	double		fov;
	int			mouse_flag;
	int			mouse_x;
	int			mouse_y;
}				t_data;

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		steps;
	float	x;
	float	y;
	float	xinc;
	float	yinc;
}				t_dda;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

//ray_Casting
void	cast_rays(t_data *data);
void	cast_ray(t_data *data, t_ray *ray);
int		calcul_distance(t_data *data, t_ray *ray);
void	vertical_casting(t_data *data, t_ray *ray);
bool	is_a_wall(t_data *data, double x, double y);
void	horizontal_casting(t_data *data, t_ray *ray);
double	distance(t_player *player, double x, double y);

//textures
void	init_wall_tex(t_data *data);
void	init_door_tex(t_data *data);
void	init_anim_tex(t_data *data);
t_tex	*select_tex(t_data *data, t_ray *ray);

//hooks and events
void	mlx_hooks(t_data *data);
int		close_win_mouse(t_data *data);
int		keyboard_event(int key, t_data *data);
void	up_key(t_player *player, t_data *data);
void	down_key(t_player *player, t_data *data);
void	left_key(t_player *player, t_data *data);
void	right_key(t_player *player, t_data *data);
int		close_win_keyboard(int key, t_data *data);

//rendring
int		render(t_data *data);
void	render_walls(t_data *data);
void	render_player(t_data *data);
void	render_map(t_data *data, int **map);
void	reset_img(t_data *data, int width, int height);
void	draw_line(t_point *p1, t_point *p2, t_mlx *mlx_data);

//utils
int		ft_abs(int n);
void	free_memory(t_data *data);
double	valid_angle(double angle);
void	free_tex(t_data *data);
bool	ray_facing_up(double angle);
bool	ray_facing_down(double angle);
bool	ray_facing_left(double angle);
bool	ray_facing_right(double angle);
int		move_player(int key, t_data *data);
void	check_door_hit(t_data *data, t_ray *ray);
int		point_color(int color1, int color2, int x2, int x);
void	my_mlx_pixel_put(t_mlx *mlx_data, int x, int y, int color);
void	my_mlx_pixel_put(t_mlx *mlx_data, int x, int y, int color);
void	mini_map_pixel_put(t_mlx *mlx_data, int x, int y, int color);

# define MAP_INFO 6

typedef struct s_program
{
	int	i;
	int	no_texture;
	int	so_texture;
	int	we_texture;
	int	ea_texture;
	int	floor;
	int	ceiling;
}			t_program; // used on implementation parsing

//parsing
void	check_existing_textures(t_map *map);
void	get_height_width_map(t_map *map);
void	parsing(t_map *map_info, char *filename);
void	check_isvalid_map(t_map *map_info);
void	check_isvalid_mapinfo(t_map *map_info);
void	check_map_infos_components(char **arr);
void	check_xmp_textures(char **arr);
void	check_rgb_colors(char **arr, char *s, int *color);
void	check_textures_colors(char **arr);
void	check_map_is_closed(char **arr, t_map *map);
void	read_map(t_map *map_info, int fd);
int		compare_tool(char *s);
int		modified_ft_atoi(const char *nptr);
void	check_is_oneplayer(char **arr, t_map *map_info);
int		find_component(char c);
void	free_arr(char **arr);
void	get_direction(t_map *map);
void	open_and_check_file(char *filename, int *fd);
void	setup_map(t_map *map_info);

//errors
void	ft_error(char type, char **arr);
void	ft_exit(char *str, char **arr);
void	ft_exit1(char *err, char *s);

#endif