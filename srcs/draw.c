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
	float y = d->posY + 2.5;
	float x = d->posX + 2.5;

	//printf("cos pdx => %f\tsin pdY %f\n", d->pdX, d->pdY);
	//printf("%f\n", d->pa);
	//vertical
	if (d->pa == 0.0 && d->pdX > 0)
		while (x < d->posX + 2.5 + rx)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x++, y, color);
	else if (d->pa == PI && d->pdX < 0)
	{
		while (x > d->posX + 2.5 - rx)
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
	draw_player(d);
}

void	draw_ray3d(t_data *d)
{
	int r, mx, my, mp, dof, mapX, mapY; 
	float rx, ry, ra, xo, yo;
	float aTan;
	
	ra = d->pa;
	for (r = 0; r < 1; r++)
	{
		//check horizontal line
		dof = 0;
		aTan = -1/tan(ra);
		if (ra == 0.0 || ra == PI)//looking straight left or right LEFT
		{
			rx = d->posX;
			ry = d->posY;
			dof = 8;
		}
		if (ra > PI)//looking up HORIZONTAL
		{
			//printf("pos => %f\n", d->posY);
			ry = (((int)d->posY >> 6) << 6) - 0.0001;
			rx = (d->posY - ry) * aTan + d->posX;
	 		yo = -32;
			xo = -yo * aTan;
		}
		if (ra < PI) //looking down HORIZONTAL
		{
			ry = (((int)d->posY >> 6) << 6) + 32;
			rx = (d->posY - ry) * aTan + d->posX;
			yo = 32;
			xo = -yo * aTan;
		}	
		while (dof < 8)
		{
			mx = (int) (rx) >> 6; my  = (int) (ry) >> 6;
			//printf("mx ==== %d\n", (int)d->posY/32);
			mp = my * ft_strlen(d->map[(int)d->posY/32]) + mx;
			//printf("my ==== %d\n", my);
			if (mp < ft_strlen(d->map[(int)d->posY/32]) * 14 \
			&& d->map[my][mx] == '1')//hit wall
				dof = 8;
			else
			{	
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
	}
	draw_direction(d, COL_DIR_P, rx, ry);
}