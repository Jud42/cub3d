#include "../includes/cub3d.h"

void	draw_player(t_data *d)//test implementation rotate P
{
	float y = d->posY;
	float x = d->posX;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, COLOR_P);
		}
		x = d->posX;
		y++;
	}
    //draw_direction(d, COL_DIR_P, x, y);
    draw_ray3d(d);
}

void	draw_empty(t_data *d)//test implementation rotate P
{
	float y = d->posY;
	float x = d->posX;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, COLOR_B);
		}
		x = d->posX;
		y++;
	}
}

void	draw_direction(t_data *d, int color, float rx, float ry)
{
	float y = d->posY;// + 2.5;
	float x = d->posX; // + 2.5;

	//printf("cos pdx => %f\tsin pdY %f\n", d->pdX, d->pdY);
	//printf("%f\n", d->pa);
	//vertical
	if (d->pa == 0.0 && d->pdX > 0)
		while (x < d->posX + rx)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, color);
	else if (d->pa == PI && d->pdX < 0)
	{
		while (x > d->posX - rx)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x--, y, color);
	}
	else if (d->pdY > 0)
	{
		while (y < (d->pdY + d->posY) + ry)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, color);
			x += d->pdX/5;
			y += d->pdY/5;
		}
	}
	else if (d->pdY < 0)
	{
		while (y > (d->pdY + d->posY) - ry)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, color);
			x += d->pdX/5;
			y += d->pdY/5;
		}
	}
}

void	draw_ray3d(t_data *d)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
    ra = FixAng(d->pa + 30);

	float aTan = -1/tan(ra);


}