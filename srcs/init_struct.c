#include "cub3d.h"

void    init_all(t_cube *cube, t_elements *elem)
{
        elem->NO = 0;
        elem->SO = 0;
        elem->WE = 0;
        elem->EA = 0;
        elem->F = 0;
        elem->C = 0;
        elem->N = 0;
        elem->S = 0;
        elem->E = 0;
        elem->W = 0;
        cube->y = 0;
        cube->x = 0;
        cube->start_map = 0;
        cube->elem = elem;
}
