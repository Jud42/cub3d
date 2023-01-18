#include "../includes/cub3d.h"

int	ft_keyrelease(int keycode, t_ray *r)
{
	if (keycode == UP)
		;
	if (keycode == DOWN)
		;
	if (keycode == ROT_LEFT)
		;
	if (keycode == ROT_RIGHT)
		;
	return (0);
}

static void left_or_right (int key, t_ray *r)
{
    double x;
    double y;

    if(key == LEFT)
    {
        x = r->posX + r->movespeed * r->pdY;
        y = r->posY - r->movespeed * r->pdX;
        if (r->map[(int)y][(int)x] == '0')
        {
            r->posX = x;
            r->posY = y;
        }
    }
    if(key == RIGHT)
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

static void	rotation_right(t_ray *r)
{
	double	pa_cam;

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

static void	rotation_left(t_ray *r)
{	
	double	pa_cam;

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

static void	up_or_down(int key, t_ray *r)
{
	if (key == UP)
	{
		if (r->map[(int)(r->posY + r->pdY * \
		r->movespeed * 2)][(int)r->posX] == '0')
			r->posY += r->pdY * r->movespeed;
		if (r->map[(int)r->posY][(int)(r->posX + r->pdX * \
		r->movespeed * 2)] == '0')
			r->posX += r->pdX * r->movespeed;
	}
	else if (key == DOWN)
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
	//printf("%d\n", keycode);
	if (keycode == UP || keycode == DOWN)
		up_or_down(keycode, r);
	else if (keycode == ROT_LEFT)
		rotation_left(r);
	else if (keycode == ROT_RIGHT)
		rotation_right(r);
    else if (keycode == LEFT || keycode == RIGHT)
        left_or_right(keycode, r);
	else if (keycode == CLOSE)
		ft_close(r);
	return (0);
}
