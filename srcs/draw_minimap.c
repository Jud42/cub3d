#include "../includes/cub3d.h"
/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */
/*
void	my_mlx_pixel_put(t_img *t, int x, int y, int color)
{
	char	*dst;

	dst = t->addr + (y * t->line_length + x * (t->bpp / 8));
	*(unsigned int*)dst = color;
}*/

/*-------------------*/ //for 2dmap
void	draw_empty(t_ray *r)//test implementation rotate P
{
	float y = r->posY;
	float x = r->posX;
	while (y < r->posY + 5)
	{
		while (x < r->posX + 5)
		{
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win,\
			x++, y, 0x000000);
		}
		x = r->posX;
		y++;
	}
}

void	draw_player(t_ray *r)//test implementation rotate P
{
	double y = r->posY;
	double x = r->posX;
	while (y < r->posY + 5)
	{
		while (x < r->posX + 5)
		{
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win,\
			x++, y, COLOR_P);
		}
		x = r->posX;
		y++;
	}
}

void	draw_direction(t_ray *r, int color, double rx, double ry)
{	
	double y = r->posY + 2.5;
	double x = r->posX + 2.5;

	
	printf("cos pdx => %f\tsin pdY %f\n", r->pdX, r->pdY);
	printf("%f\n", r->pa);
	//vertical
	if (r->pa == 0.0 && r->pdX > 0)
		while (x < r->posX + 2.5 + rx)
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win, x++, y, color);
	else if (r->pa == PI && r->pdX < 0)
	{
		while (x > r->posX + 2.5 - rx)
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win, x--, y, color);		
	}
	else if (r->pdY > 0)	
	{
		while (y < (r->pdY + r->posY) + ry)
		{
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win, x, y, color);
			x += r->pdX/5;
			y += r->pdY/5;
		}
	}
	else if (r->pdY < 0)
	{
		while (y > (r->pdY + r->posY) - ry + PIX + 2.5)
		{
			mlx_pixel_put(r->data->mlx_ptr, r->data->mlx_win, x, y, color);
			x += r->pdX/5;
			y += r->pdY/5;
		}
	}
	draw_player(r);
}


void	print_wall(t_ray *r)
{
	r->y = 0;
	while (r->map[r->y])
	{
		r->x = -1;
		while (r->map[r->y][++r->x])
		{
			if (r->map[r->y][r->x] == '1')
			{
				mlx_put_image_to_window(r->data->mlx_ptr,\
			r->data->mlx_win, r->data->texture[0].img, r->x * PIX, r->y * PIX);
			}
		}
		r->y++;
	}
}
/*---------------------*/
