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
	//printf("%d\n", keycode);	
	if (keycode == UP)
	{
		//draw_direction(d, 0x000000, 10, 10);
		draw_empty(d);
		d->posY += d->pdY*5;
		draw_player(d);
	}
	if (keycode == DOWN)
	{
		//draw_direction(d, 0x000000, 10,10);
		draw_empty(d);
		d->posY -= d->pdY*5;
		draw_player(d);
	}
	if (keycode == LEFT)
	{
		draw_empty(d);
		d->posX += d->pdX*5;
		draw_player(d);
	}
	if (keycode == RIGHT)
	{
		draw_empty(d);
		d->posX -= d->pdX*5;
		draw_player(d);
	}
	if (keycode == ROT_LEFT)
	{
		//draw_direction(d, 0x000000, 10, 10);
		d->pa-= 0.1;
		if (d->pa < 0)
			d->pa += 2 * PI;
		d->pdX = cos(d->pa) * 5;
		d->pdY = sin(d->pa) * 5;
	}
	if (keycode == ROT_RIGHT)
	{
		//draw_direction(d, 0x000000, 10, 10);
		d->pa += 0.1;
		if (d->pa > 2 * PI)
			d->pa -= 2 * PI;
		d->pdX = cos(d->pa) * 5;
		d->pdY = sin(d->pa) * 5;
	}
	if (keycode == KEY_ESC)
		close_window(d);
	//draw_ray3d(d);
	return (0);
}