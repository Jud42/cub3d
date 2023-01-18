#ifndef CUB3D_H
 # define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx.h"
#include <math.h>
#include <time.h>
#include "libft.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define EXIT 1
#define PIX 64 //64 Height & 64 Width
#define COLOR_P	0x00FF0000 //test pixel 
#define COL_DIR_P	0x000066FF //test pixel 
#define COL_TEST	0x0000FF66 //test pixel 
#define PI 3.1415926535//pi value

# ifdef __linux__ //clavier azerty
	# define UP 122
	# define DOWN 115
	# define ROT_LEFT 65361
	# define ROT_RIGHT 65363
    # define LEFT 113
    # define RIGHT 100
	# define CLOSE 65307 
# else //mac
	# define UP 13
	# define DOWN 1
	# define ROT_LEFT 123
	# define ROT_RIGHT 124
    # define LEFT 0
    # define RIGHT 2
    # define CLOSE 53
# endif

typedef struct s_color{
	int RED;
	int GREEN;
	int BLUE;
} t_color;

typedef struct s_elements{
	char	*NO; //path north texture wall
	char	*SO; //path south texture wall
	char	*WE; //path west texture wall
	char	*EA; //path east texture wall
	int	F; //color sol
	int	C; //color plafond
}	t_elements;

typedef struct s_img
{
	void	*img;
	int	*addr;
	int	width;
	int	height;
	int	bpp; 	/* bits per pixel */
	int	line_length;
	int	endian;
}	t_img;

typedef struct s_data{
	void 	*mlx_ptr;
	void 	*mlx_win;
	int	screen_w;
	int	screen_h;	
	void	*img;
	int	*addr;
	int	bpp;
	int	line_length;
	int	endian;
	t_img	texture[4];
}	t_data;

typedef struct s_text
{
	int	texX;
	int	texY;
	int	texdir;
	double	texpos;
	double	step;
	double	wallX;
}	t_text;

typedef struct s_ray{
	int	x;
	int	y;
	char	**map;
	int	mapX;
	int	mapY;
	char	pos;
	double	posX;
	double	posY;
	double	pdX;
	double	pdY;
	double	pa;
	double	planX;
	double	planY;	
	double	time;
	double	oldtime;
	double	movespeed;
	double	rotspeed;
	double	cameraX;
	double	raydirX;
	double	raydirY;
	double	sidedstX;
	double	sidedstY;
	double	deltadstX;
	double	deltadstY;
	double	perpdwalldst;
	int	**buffer;
	int	stepX;
	int	stepY;
	int	lineHeight;
	int	drawstart;
	int	drawend;
	int	hit;
	int	side;
	t_elements	*elem;
	t_data 	*data;
}	t_ray;

	
int msg_error(char *s, int flag);
char **create_tab(char *file);
int init_all(t_ray *ray, char *file);
void check_error_argument(int ac, char **av);
int	take_map(t_ray *r);
int	parse_map(t_ray *r);
void clean_all(t_ray *r, int flag);
void clean_tab(char **tab, int flag);
void	clean_element(t_elements **elem);
void	fill_map(t_ray *r);
int	take_color(char *line, t_elements *elem);

//temp draw
void	draw_empty(t_ray *r);
void	draw_player(t_ray *r);
void	draw_direction(t_ray *r, int color, double rx, double ry);
void	print_wall(t_ray *r);
void	ray_cast(t_data *d);

//temp event
int 	ft_keypress(int keycode, t_ray *r);
int	ft_keyrelease(int keycode, t_ray *r);

int	init_texture(t_ray *r);
void	ft_draw_column(t_ray *r);
int	raycasting(t_ray *r);

void	init_dir_and_plancam(t_ray *r);
void	clean_image(t_ray *r);
void	calcul_time(t_ray *r);
char	*conv_hexe(int n);
int	ft_atoi_hexe(const char *str);

int	ft_close(t_ray *r);
#endif 

