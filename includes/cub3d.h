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

typedef struct s_color{
	int RED;
	int GREEN;
	int BLUE;
} t_color;

typedef struct s_elements{
	int	NO; //path north texture wall
	int	SO; //path south texture wall
	int	WE; //path west texture wall
	int	EA; //path east texture wall
	int	*F; //color sol
	int	*C; //color plafond
	int	N; //first position players
	int	S; //first position players
	int	E; //first position players
	int	W; //first position players

}	t_elements;

typedef struct s_data{
	void *mlx_ptr;
	void *mlx_win;
	int  width;
	int  height;
}	t_data;

typedef struct s_cube{
	int	x;
	int	y;
	int	start_map;
	char	**tab;
	t_data	*mlx;
	t_elements *elem;
}	t_cube;

int msg_error(char *s);
void parse_map(t_cube *cube, t_elements *elem);
char **create_tab(char *file);
void init_all(t_cube *cube, t_elements *elem);
void check_error_argument(int ac, char **av);
void check_elements(t_cube *cube);
void check_description(t_cube *c);
void clean_all(t_cube *cube, int flag);
void clean_tab(char **tab, int flag);

#endif 

