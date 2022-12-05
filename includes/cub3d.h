#ifndef CUB3D_H
 # define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx.h"
#include <math.h>
#include "libft.h"

#define EXIT 1
#define H_PIX 32 //Height
#define W_PIX 32 //Width
#define COLOR_P	0x00FF0000 //test pixel 
#define COL_DIR_P	0x000066FF //test pixel 

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
	int	N; //first position players
	int	S; //first position players
	int	E; //first position players
	int	W; //first position players

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
	void *mlx_ptr;
	void *mlx_win;
	t_img	*img;
	int  width;
	int  height;
}	t_data;

typedef struct s_cube{
	int		x;
	int		y;
	char	**map;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planX;
	double	planY;
	t_data		*data;
	t_elements	*elem;
}	t_cube;

int msg_error(char *s);
char **create_tab(char *file);
int init_all(t_cube *cube, char *file);
void check_error_argument(int ac, char **av);
int	take_map(t_cube *cube);
int	parse_map(t_cube *c);
void clean_all(t_cube *cube, int flag);
void clean_tab(char **tab, int flag);

#endif 

