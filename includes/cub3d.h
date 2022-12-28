#ifndef CUB3D_H
 # define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"

#define EXIT 1
#define H_PIX 16 //Height
#define W_PIX 16 //Width
#define WIN_W 800
#define WIN_H 600
#define COLOR_P	0x00FF0000 //test pixel
#define COLOR_B 0x000000 
#define COL_DIR_P	0x000066FF //test pixel 
#define COL_TEST	0x0000FF66 //test pixel 
#define PI 3.1415926535//pi value
#define KEY_ESC 53
#define COL_RAY2D   0x68228B //test pixel
#define COLOR_WALL  0xffffff
#define COLOR_SPR   0x33228b
# if defined (_linux_) //clavier azerty
	# define UP 122
	# define DOWN 115
	# define LEFT 113
	# define RIGHT 100
	# define ROT_LEFT 65361
	# define ROT_RIGHT 65363
    # define arrow_up 65365
    # define arrow_down 65366
# else //clavier qwerty
	# define UP 13
	# define DOWN 1
	# define LEFT 0
	# define RIGHT 2
	# define ROT_LEFT 123
	# define ROT_RIGHT 124
    # define arrow_up 126
    # define arrow_down 125
# endif

typedef struct s_color
{
	int RED;
	int GREEN;
	int BLUE;
} t_color;

typedef struct s_elements
{
	void	*NO; //path north texture wall
	void	*SO; //path south texture wall
	void	*WE; //path west texture wall
	void	*EA; //path east texture wall
	int		*F; //color sol
	int		*C; //color plafond
}	t_elements;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; 	/* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

// Structure to represent a point in 2D space
typedef struct s_point
{
    double x;
    double y;
} t_point;

// Structure to represent a line in 2D space
typedef struct s_line
{
    t_point start;
    t_point end;
} t_line;

typedef struct s_data
{
    int  	width;
    int  	height;
    int		x;
    int		y;
    char	**map;
    float	posX;
    float	posY;
    float	pdX;
    float	pdY;
    float	pa;
    float	dirX;
    float	dirY;
    float	planX;
    float	planY;
    float  resY;
    float  resX;
    char	*addr;
    int		bpp;
    int		size_line;
    void 	*mlx_ptr;
    void 	*mlx_win;
    t_img		*img;
    t_elements	*elem;
}	t_data;
	
int 	msg_error(char *s);
char 	**create_tab(char *file);
int 	init_all(t_data *data, char *file);
void 	check_error_argument(int ac, char **av);
int		take_map(t_data *d);
int		parse_map(t_data*d);
void 	clean_all(t_data *d, int flag);
void 	clean_tab(char **tab, int flag);
int		close_window(t_data *data);
int		take_keycode(int keycode, t_data *d);
void	draw_ray3d(t_data *d);
void	draw_player(t_data *d);
void	draw_empty(t_data *d);
void	draw_direction(t_data *d, int color, float rx, float ry);
int 	FixAng(int a);
float 	degToRad(int a);
int     collision(t_data *d, float x, float y);
void    cast_all_rays(t_data *d);
void    castRay(t_data *d );
void	img_pix_put(t_img *img, int x, int y, int color);

#endif 

