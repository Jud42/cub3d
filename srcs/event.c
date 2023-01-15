#include "../includes/cub3d.h"
//test pour le num clavier
static int	check_wall(int key, t_ray *r)
{
    char	c;

    c = ' ';
    if (key == UP)
        c = r->map[(int)(r->posY + r->pdY)][(int)(r->posX + r->pdX)];
    else if (key == DOWN)
        c = r->map[(int)(r->posY - r->pdY)][(int)(r->posX - r->pdX)];
    if (c != '1' && c != '\0')
        return (0);
    return (1);
}
int	take_keycode(int keycode, t_ray *r)
{
    printf("%d\n", keycode);
    if (keycode == UP && check_wall(keycode, r) != 1)
    {
        //draw_direction(d, 0x000000, 10, 10);
        //draw_empty(d);
        r->posX+= r->pdX;
        r->posY+= r->pdY;
        //draw_player(d);
    }
    if (keycode == DOWN && check_wall(keycode, r) != 1)
    {
        //draw_direction(d, 0x000000, 10,10);
        //draw_empty(d);
        r->posX-= r->pdX;
        r->posY-= r->pdY;
        //draw_player(d);
    }
    if (keycode == ROT_LEFT)
    {
        //draw_direction(d, 0x000000, 10, 10);
        r->pa-= 0.1;
        if (r->pa < 0)
            r->pa += 2 * PI;
        r->pdX = cos(r->pa); //* 5;
        r->pdY = sin(r->pa); //* 5;
    }
    if (keycode == ROT_RIGHT)
    {
        //draw_direction(d, 0x000000, 10, 10);
        r->pa += 0.1;
        if (r->pa > 2 * PI)
            r->pa -= 2 * PI;
        r->pdX = cos(r->pa);
        r->pdY = sin(r->pa);
    }
    return (0);
}