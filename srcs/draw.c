#include "../includes/cub3d.h"

void	draw_player(t_data *d)
{
    /*Point start;
   start.x = 5;
   start.y = 5;
   double angle = M_PI / 4;
   Point intersection;
   castRay(start, angle, map, &intersection);
   printf("Intersection at (%f, %f)\n", intersection.x, intersection.y);*/
    t_point start;
    t_point intersection;
	start.y = d->posY;
	start.x = d->posX;
	while (start.y < d->posY + 5)
	{
		while (start.x < d->posX + 5)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, start.x++, start.y, COLOR_P);
        start.x = d->posX;
        start.y++;
	}
    //cast_all_rays(d);
    castRay(start, d->pa, d, &intersection);
    printf("Intersection at (%f, %f)\n", intersection.x, intersection.y);
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