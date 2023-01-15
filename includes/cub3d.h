#ifndef CUB3D_H
 # define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lib/mlx/mlx.h"
#include <math.h>
#include "../lib/libft/libft.h"

#define EXIT 1
#define PIX 64 //64 Height & 64 Width
#define COLOR_P	0x00FF0000 //test pixel 
#define COL_DIR_P	0x000066FF //test pixel 
#define COL_TEST	0x0000FF66 //test pixel 
#define PI 3.1415926535//pi value

# if defined (_linux_) //clavier azerty
	# define UP 122
	# define DOWN 115
	//# define LEFT 113
	//# define RIGHT 100
	# define ROT_LEFT 113
	# define ROT_RIGHT 100
# else //clavier qwerty
	# define UP 13
	# define DOWN 1
	# define ROT_LEFT 0
	# define ROT_RIGHT 2
# endif

typedef struct s_color{
	int RED;
	int GREEN;
	int BLUE;
} t_color;

typedef struct s_elements{
	void	*NO; //path north texture wall
	void	*SO; //path south texture wall
	void	*WE; //path west texture wall
	void	*EA; //path east texture wall
	int	*F; //color sol
	int	*C; //color plafond
}	t_elements;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp; 	/* bits per pixel */
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_data{
	int  	width;
	int  	height;
	int	x;
	int	y;
	char	**map;
	int		mapX;
	int		mapY;
	float	posX;
	float	posY;
	float	pdX;
	float	pdY;
	double	pa;
	float	dirX;
	float	dirY;
	float	planX;
	float	planY;
	void 	*mlx_ptr;
	void 	*mlx_win;
	t_img		*img;
	t_elements	*elem;
}	t_data;
	
int msg_error(char *s);
char **create_tab(char *file);
int init_all(t_data *data, char *file);
void check_error_argument(int ac, char **av);
int	take_map(t_data *d);
int	parse_map(t_data*d);
void clean_all(t_data *d, int flag);
void clean_tab(char **tab, int flag);
void	fill_map(t_data *d);

//temp draw
void	draw_empty(t_data *d);
void	draw_player(t_data *d);
void	draw_direction(t_data *d, int color, double rx, double ry);
void	print_wall(t_data *d);
void	ray_cast(t_data *d);

//temp event
int take_keycode(int keycodde, t_data *d);

#endif 

