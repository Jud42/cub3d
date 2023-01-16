#include "cub3d.h"

int	take_keycode(int keycode, t_ray *r)
{
	double	oldplanY;
	double oldDirY; 
	double	pa_cam;

	oldDirY= r->pdY;
	oldplanY = r->planY;
	printf("%d\n", keycode);
	if (keycode == UP)
	{
		if (r->map[(int)(r->posY + r->pdY * \
		r->movespeed * 2)][(int)r->posX] == '0')
			r->posY += r->pdY * r->movespeed;
		if (r->map[(int)r->posY][(int)(r->posX + r->pdX * \
		r->movespeed * 2)] == '0')
			r->posX += r->pdX * r->movespeed;
	}
	else if (keycode == DOWN)
	{
		if (r->map[(int)(r->posY - r->pdY * \
		r->movespeed * 2)][(int)r->posX] == '0')
			r->posY -= r->pdY * r->movespeed;
		if (r->map[(int)r->posY][(int)(r->posX - r->pdX * \
		r->movespeed * 2)] == '0')
			r->posX -= r->pdX * r->movespeed;
	}
	else if (keycode == ROT_LEFT || keycode == 65361)
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

      		/*r->pdY = r->pdY * cos(r->rotspeed) - r->pdX * sin(r->rotspeed);
      		r->pdX = oldDirY * sin(r->rotspeed) + r->pdX * cos(r->rotspeed);

		r->planY = r->planY * cos(r->rotspeed) - r->planX * sin(r->rotspeed); 
		r->planX = oldplanY * sin(r->rotspeed) + r->planX * cos(r->rotspeed);*/
	}
	else if (keycode == ROT_RIGHT || keycode == 65363)
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
      		/*r->pdY = r->pdY * cos(-r->rotspeed) - r->pdX * sin(-r->rotspeed);
      		r->pdX = oldDirY * sin(-r->rotspeed) + r->pdX * cos(-r->rotspeed);

		r->planY = r->planY * cos(-r->rotspeed) - r->planX * sin(-r->rotspeed); 
		r->planX = oldplanY * sin(-r->rotspeed) + r->planX * cos(-r->rotspeed);*/
	}
	return (0);
}
