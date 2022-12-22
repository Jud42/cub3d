#include "cub3d.h" 

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

void	draw_empty(t_data *d)//test implementation rotate P
{
	float y = d->posY;
	float x = d->posX;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win,\
			x++, y, 0x000000);
		}
		x = d->posX;
		y++;
	}
}

/*---------------------------*/
void	draw_player(t_data *d)//test implementation rotate P
{
	double y = d->posY;
	double x = d->posX;
	while (y < d->posY + 5)
	{
		while (x < d->posX + 5)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win,\
			x++, y, COLOR_P);
		}
		x = d->posX;
		y++;
	}
}

/*----------------------------*/
void	draw_direction(t_data *d, int color, double rx, double ry)
{	
	double y = d->posY + 2.5;
	double x = d->posX + 2.5;

	
	printf("cos pdx => %f\tsin pdY %f\n", d->pdX, d->pdY);
	printf("%f\n", d->pa);
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
		while (y > (d->pdY + d->posY) - ry + PIX + 2.5)
		{
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, color);
			x += d->pdX/5;
			y += d->pdY/5;
		}
	}
	draw_player(d);
}

/*-------------------*/
static void	init_wall(void **texture, void **mlx_ptr)
{
	int	width;
	int	height;
	void 	*path;
	
	path = mlx_xpm_file_to_image(*mlx_ptr, (char *)*texture, &width, &height);
	free(*texture);
	*texture = path;
}

void	print_wall(t_data *d)
{
	if (d->elem->NO)
		init_wall(&d->elem->NO, &d->mlx_ptr);
	if (d->elem->SO)
		init_wall(&d->elem->SO, &d->mlx_ptr);
	if (d->elem->EA)
		init_wall(&d->elem->EA, &d->mlx_ptr);
	if (d->elem->WE)
		init_wall(&d->elem->WE, &d->mlx_ptr);
	d->y = 0;
	while (d->map[d->y])
	{
		d->x = -1;
		while (d->map[d->y][++d->x])
		{
			if (d->map[d->y][d->x] == '1')
			{
				mlx_put_image_to_window(d->mlx_ptr,\
			d->mlx_win, d->elem->EA, d->x * PIX, d->y * PIX);
			}
		}
		d->y++;
	}
}
