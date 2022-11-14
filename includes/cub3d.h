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

typedef struct s_cube{
	int	y;
	int	x;
	int	start_map;
	char	**tab;
	t_elements *elem;
}	t_cube;

void parse_map(int ac, char **av);
void clean_tab(char **tab, int flag);
#endif 

