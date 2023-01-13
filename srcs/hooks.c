#include "../includes/cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->view3d.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	take_keycode(int keycode, t_data *d)
{
	if (keycode == UP || keycode == arrow_up)
	{
        //castRay(d);
		if(!collision(d, d->player.pos.x, d->player.pos.y))
		{
			//draw_empty(d);
			d->player.pos.x += d->player.dir.y*5;
			d->player.pos.y += d->player.dir.x*5;
			//draw_player(d);
		}
        else
        {
            //draw_empty(d);
            d->player.pos.y -= d->player.dir.y*5;
            d->player.pos.x -= d->player.dir.x*5;
            //draw_player(d);
        }
	}
	if (keycode == DOWN || keycode == arrow_down)
	{
        if(!collision(d, d->player.pos.x, d->player.pos.y))
		{
			//draw_empty(d);
            d->player.pos.y -= d->player.dir.y*5;
            d->player.pos.x -= d->player.dir.x*5;
			//draw_player(d);
		}
        else
        {
            //draw_empty(d);
            d->player.pos.y += d->player.dir.y*5;
            d->player.pos.x += d->player.dir.x*5;
            //draw_player(d);
        }
	}

	if (keycode == LEFT || keycode == ROT_LEFT)
	{
		//draw_empty(d);
		d->player.angle += 1;
		FixAng(d->player.angle);
		d->player.dir.x=cos(degToRad(d->player.angle));
		d->player.dir.y=-sin(degToRad(d->player.angle));
		//draw_player(d);
	}
	if (keycode == RIGHT || keycode == ROT_RIGHT)
	{
		//draw_empty(d);
		d->player.angle -= 1;
		FixAng(d->player.angle);
		d->player.dir.x=cos(degToRad(d->player.angle));
		d->player.dir.y=-sin(degToRad(d->player.angle));
		//draw_player(d);
	}
	if (keycode == KEY_ESC)
		close_window(d);
	return (0);
}