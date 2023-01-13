#include "../includes/cub3d.h"

void	draw_player(t_data *d)
{
    float x;
    float y;
    x = d->player.pos.x;
    y = d->player.pos.y;
	while (y < d->player.pos.y + 5)
	{
		while (x < d->player.pos.x + 5)
			mlx_pixel_put(d->mlx, d->win, x++, y, COLOR_P);
        x = d->player.pos.x;
        y++;
	}
}

void	draw_empty(t_data *d)
{
    float y = d->player.pos.y;
    float x = d->player.pos.x;
	while (y < d->player.pos.y + 5)
	{
		while (x < d->player.pos.x + 5)
			mlx_pixel_put(d->mlx, d->win, x++, y, COLOR_B);
		x = d->player.pos.x;
		y++;
	}
}

void draw_ray3d(t_data *d)
{
    float y = d->player.pos.y + 2.5;
    float x = d->player.pos.x + 2.5;
    int i = 0;
    while (i < 100)
    {
        mlx_pixel_put(d->mlx, d->win, x, y, COL_RAY2D);
        x += d->player.dir.x/5;
        y += d->player.dir.y/5;
        i++;
    }
}

void cast_ray(t_data *d)
{
    float x = d->player.pos.x;
    float y = d->player.pos.y;
    int i = 0;
    while (i < 100)
    {
        mlx_pixel_put(d->mlx, d->win, x, y, COL_RAY2D);
        x += d->player.dir.x/5;
        y += d->player.dir.y/5;
        i++;
    }
}

void cast_all_rays(t_data *d)
{
    float angle = d->player.angle;
    int i = 0;
    while (i < 100)
    {
        d->player.dir.x = cos(angle);
        d->player.dir.y = -sin(angle);
        cast_ray(d);
        angle += 0.01;
        i++;
    }
}