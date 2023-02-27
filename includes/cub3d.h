/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:21:27 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/03 21:38:28 by btchiman         ###   42Lausanne.ch     */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
 # define _CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "keys_texture.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define EXIT 1
# define PIX 64
# define COLOR_P	0x00FF0000 
# define COL_DIR_P	0x000066FF 
# define COL_TEST	0x0000FF66 
# define PI 3.1415926535

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_move
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}	t_move;

typedef struct s_elements
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_elements;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		screen_w;
	int		screen_h;	
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_img	texture[4];
}	t_data;

typedef struct s_text
{
	int		tex_x;
	int		tex_y;
	int		texdir;
	double	texpos;
	double	step;
	double	wallx;
}	t_text;

typedef struct s_ray
{
	int			x;
	int			y;
	char		**map;
	int			mapx;
	int			mapy;
	char		pos;
	double		posx;
	double		posy;
	double		pdx;
	double		pdy;
	double		pa;
	double		planx;
	double		plany;	
	double		time;
	double		oldtime;
	double		movespeed;
	double		rotspeed;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedst_x;
	double		sidedst_y;
	double		deltadst_x;
	double		deltadst_y;
	double		perpdwalldst;
	int			**buffer;
	int			step_x;
	int			step_y;
	int			line_height;
	int			drawstart;
	int			drawend;
	int			hit;
	int			side;
	t_move		move;
	t_elements	*elem;
	t_data		*data;
}	t_ray;

int		msg_error(char *s, int flag);
char	**create_tab(char *file);
int		init_all(t_ray *ray, char *file);
void	check_error_argument(int ac, char **av);
int		take_map(t_ray *r);
int		parse_map(t_ray *r);
void	clean_all(t_ray *r, int flag);
void	clean_tab(char **tab, int flag);
void	clean_element(t_elements **elem);
void	fill_map(t_ray *r);
int		take_color(char *line, t_elements *elem);
int		nb_line_tab(char *file);
//temp draw
void	draw_empty(t_ray *r);
void	draw_player(t_ray *r);
void	draw_direction(t_ray *r, int color, double rx, double ry);
void	print_wall(t_ray *r);
void	ray_cast(t_data *d);

//temp event
int		ft_keypress(int keycode, t_ray *r);
int		ft_keyrelease(int keycode, t_ray *r);

int		init_texture(t_ray *r);
void	ft_draw_column(t_ray *r);
int		raycasting(t_ray *r);

void	init_dir_and_plancam(t_ray *r);
void	clean_image(t_ray *r);
void	calcul_time(t_ray *r);
char	*conv_hexe(int n);
int		ft_atoi_hexe(const char *str);

// move
void	init_move(t_ray *r);
void	move(t_ray *r);
void	left_or_right(t_ray *r);
void	rotation_right(t_ray *r);
void	rotation_left(t_ray *r);
void	up_or_down(t_ray *r);

int		ft_close(t_ray *r);

#endif 
