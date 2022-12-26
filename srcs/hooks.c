#include "../includes/cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
}

//test pour le num clavier
int	take_keycode(int keycode, t_data *d)
{
	if (keycode == UP)
	{
		if(!collision(d, d->posX, d->posY))
		{
			draw_empty(d);
			d->posY += d->pdY*5;
			d->posX += d->pdX*5;
			draw_player(d);
		}
        else
        {
            draw_empty(d);
            d->posY -= d->pdY*5;
            d->posX -= d->pdX*5;
            draw_player(d);
        }
	}
	if (keycode == DOWN)
	{
        if(!collision(d, d->posX, d->posY))
		{
			draw_empty(d);
			d->posY -= d->pdY*5;
			d->posX -= d->pdX*5;
			draw_player(d);
		}
        else
        {
            draw_empty(d);
            d->posY += d->pdY*5;
            d->posX += d->pdX*5;
            draw_player(d);
        }
	}

	if (keycode == LEFT || keycode == ROT_LEFT)
	{
		draw_empty(d);
		d->pa += 5;
		FixAng(d->pa);
		d->pdX=cos(degToRad(d->pa));
		d->pdY=-sin(degToRad(d->pa));
		draw_player(d);
	}
	if (keycode == RIGHT || keycode == ROT_RIGHT)
	{
		draw_empty(d);
		d->pa -= 5;
		FixAng(d->pa);
		d->pdX=cos(degToRad(d->pa));
		d->pdY=-sin(degToRad(d->pa));
		draw_player(d);
	}
	if (keycode == KEY_ESC)
		close_window(d);
	//draw_ray3d(d);

	return (0);
}