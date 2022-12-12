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
#define H_PIX 32 //Height
#define W_PIX 32 //Width
#define COLOR_P	0x00FF0000 //test pixel 
#define COL_DIR_P	0x000066FF //test pixel 
#define COL_TEST	0x0000FF66 //test pixel 
#define PI 3.1415926535//pi value

//clavier azerty
#define UP 122
#define DOWN 115
#define LEFT 113
#define RIGHT 100
#define ROT_LEFT 65361
#define ROT_RIGHT 65363

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
	float	posX;
	float	posY;
	float	pdX;
	float	pdY;
	float	pa;
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

#endif 

