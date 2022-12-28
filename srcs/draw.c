#include "../includes/cub3d.h"

void	draw_player(t_data *d)
{
    float x;
    float y;
    x = d->posX;
    y = d->posY;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, COLOR_P);
        x = d->posX;
        y++;
	}
}

void	draw_empty(t_data *d)
{
    float y = d->posY;
    float x = d->posX;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, COLOR_B);
		x = d->posX;
		y++;
	}
}

void draw_ray3d(t_data *d)
{
    float y = d->posY + 2.5;
    float x = d->posX + 2.5;
    int i = 0;
    while (i < 100)
    {
        mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, COL_RAY2D);
        x += d->pdX/5;
        y += d->pdY/5;
        i++;
    }
}

void cast_ray(t_data *d)
{
    float x = d->posX;
    float y = d->posY;
    int i = 0;
    while (i < 100)
    {
        mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, COL_RAY2D);
        x += d->pdX/5;
        y += d->pdY/5;
        i++;
    }
}

void cast_all_rays(t_data *d)
{
    float angle = d->pa;
    int i = 0;
    while (i < 100)
    {
        d->pdX = cos(angle);
        d->pdY = -sin(angle);
        cast_ray(d);
        angle += 0.01;
        i++;
    }
}