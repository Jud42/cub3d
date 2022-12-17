#include "../includes/cub3d.h" 

/*
    North (W): 0° = 360° or 0
    South (N): 270°
    East (E): 180°
    West (S): 90°
 */

void	draw_player(t_data *d);
void	draw_empty(t_data *d);

void	draw_direction(t_data *d, int color, float rx, float ry)
{	
	float y = d->posY + 2.5;
	float x = d->posX + 2.5;

	
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
	double rx, ry, ra, xo, yo;
	double aTan;
	
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
			printf("pos => %f\n", d->posY);
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
			printf("mx ==== %d\n", (int)d->posY/32);
			mp = my * ft_strlen(d->map[(int)d->posY/32]) + mx;
			printf("my ==== %d\n", my);
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

//test pour le num clavier
int	take_keycode(int keycode, t_data *d)
{
	printf("%d\n", keycode);	
	if (keycode == UP)
	{
		//draw_direction(d, 0x000000, 10, 10);
		draw_empty(d);
		d->posX+= d->pdX;
		d->posY+= d->pdY;
		draw_player(d);
	}
	if (keycode == DOWN)
	{
		//draw_direction(d, 0x000000, 10,10);
		draw_empty(d);
		d->posX-= d->pdX;
		d->posY-= d->pdY;
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
	draw_ray3d(d);
	return (0);
}


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


void	draw_player(t_data *d)//test implementation rotate P
{
	float y = d->posY;
	float x = d->posX;
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

void	init_wall(void **texture, void **mlx_ptr)
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
			d->mlx_win, d->elem->EA, d->x * 32, d->y * 32);
			}
		}
		d->y++;
	}
}

int	main(int argc, char *argv[])
{
	t_data data;

	check_error_argument(argc, argv);
	if (init_all(&data, argv[1]))
		clean_all(&data, 1);
	print_wall(&data);
	draw_player(&data);
	draw_ray3d(&data);
	//draw_direction(&data, COL_DIR_P, 10, 10);
	mlx_key_hook(data.mlx_win, take_keycode, &data);
	mlx_loop(data.mlx_ptr);
	clean_all(&data, 0);
	return (0);
}
