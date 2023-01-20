#include "../includes/cub3d.h"

void left_or_right (t_ray *r)
{
    double x;
    double y;

    if(r->move.left)
    {
        x = r->posX + r->movespeed * r->pdY;
        y = r->posY - r->movespeed * r->pdX;
        if (r->map[(int)y][(int)x] == '0')
        {
            r->posX = x;
            r->posY = y;
        }
    }
    if(r->move.right)
    {
        x = r->posX - r->movespeed * r->pdY;
        y = r->posY + r->movespeed * r->pdX;
        if (r->map[(int)y][(int)x] == '0')
        {
            r->posX = x;
            r->posY = y;
        }
    }
}

void	rotation_right(t_ray *r)
{
	double	pa_cam;
    if(r->move.rot_right)
    {
        r->pa += 0.1;
        if (r->pa > 2 * PI)
            r->pa -= 2 * PI;
        r->pdX = cos(r->pa);
        r->pdY = sin(r->pa);
        pa_cam = r->pa + PI / 2;
        if (pa_cam > PI * 2)
            pa_cam -= PI * 2;
        r->planX = cos(pa_cam) * 0.66;
        r->planY = sin(pa_cam) * 0.66;
    }
}

void	rotation_left(t_ray *r)
{	
	double	pa_cam;
    if(r->move.rot_left)
    {
        r->pa -= 0.1;
        if (r->pa < 0.)
            r->pa += 2 * PI;
        r->pdX = cos(r->pa);
        r->pdY = sin(r->pa);
        pa_cam = r->pa + PI / 2;
        if (pa_cam < 0)
            pa_cam += PI * 2;
        r->planX = cos(pa_cam) * 0.66;
        r->planY = sin(pa_cam) * 0.66;
    }

}

void	up_or_down(t_ray *r)
{
	if (r->move.up)
	{
		if (r->map[(int)(r->posY + r->pdY * \
		r->movespeed * 2)][(int)r->posX] == '0')
			r->posY += r->pdY * r->movespeed;
		if (r->map[(int)r->posY][(int)(r->posX + r->pdX * \
		r->movespeed * 2)] == '0')
			r->posX += r->pdX * r->movespeed;
	}
	else if (r->move.down)
	{
		if (r->map[(int)(r->posY - r->pdY * \
		r->movespeed * 2)][(int)r->posX] == '0')
			r->posY -= r->pdY * r->movespeed;
		if (r->map[(int)r->posY][(int)(r->posX - r->pdX * \
		r->movespeed * 2)] == '0')
			r->posX -= r->pdX * r->movespeed;
	}
}



int	ft_keypress(int keycode, t_ray *r)
{
	if (keycode == UP)
        r->move.up = 1;
    else if (keycode == DOWN)
        r->move.down = 1;
    else if (keycode == ROT_LEFT)
        r->move.rot_left = 1;
    else if (keycode == ROT_RIGHT)
        r->move.rot_right = 1;
    else if (keycode == LEFT)
        r->move.left = 1;
    else if (keycode == RIGHT)
        r->move.right = 1;
	else if (keycode == CLOSE)
		ft_close(r);
    move(r);
	return (0);
}
