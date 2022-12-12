#include "cub3d.h" 

/*
    North (N): 0° = 360°
    East (E): 90°
    South (S): 180°
    West (W): 270°
 */

void	draw_direction(t_data *d);
void	draw_player(t_data *d);
void	draw_empty(t_data *d);

void	draw_ray3d(t_data *d)
{
	int r, mx, my, mp, dof, mapX, mapY; float rx, ry, ra, xo, yo;
	ra = d->pa;
	//check horizontal line
	dof = 0;
	float aTan = -1/tan(ra);
	mapY = -1;
	mapX = 0;
	while (d->map[++mapY])
		if (mapX < ft_strlen(d->map[mapY]))
			mapX = ft_strlen(d->map[mapY]);
	if (ra > PI)//looking up
	{
		ry = (((int)d->posY >> 6) << 6) - 0.0001;
		rx = (d->posY - ry) * aTan + d->posX;
		yo = -32;
		xo = yo * aTan;
	}
	if (ra < PI)
	{
		ry = (((int)d->posY >> 6) << 6) + 32;
		rx = (d->posY - ry) * aTan + d->posX;
		yo = 32;
		xo = yo * aTan;
	}
	if (ra == 0 || ra == PI)//looking straight left or right
	{
		rx = d->posX;
		ry = d->posY;
		dof = 8;
	}
	while (dof < 8)
	{
		mx = (int) (rx) >> 6;
		my = (int) (ry) >> 6;
		mp = my * mapX + mx;
		printf("%d\n", mp);
		if (mp < mapX * mapY)//hit wall
			dof = 8;
		else{//next line
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	mlx_pixel_put(d->mlx_ptr, d->mlx_win, rx, ry, COL_DIR_P);
}

//test pour le num clavier
int	take_keycode(int keycode, t_data *d)
{
	printf("%d\n", keycode);	
	if (keycode == UP)
	{
		draw_empty(d);
		d->posX+= d->pdX;
		d->posY+= d->pdY;
		draw_player(d);
	}
	if (keycode == DOWN)
	{
		draw_empty(d);
		d->posX-= d->pdX;
		d->posY-= d->pdY;
		draw_player(d);
	}
	if (keycode == ROT_LEFT)
	{
		d->pa-= 0.1;
		if (d->pa < 0)
			d->pa += 2 * PI;
		d->pdX = cos(d->pa) * 5;
		d->pdY = sin(d->pa) * 5;
		d->posX += d->pdX;
		d->posY += d->pdY;
	}
	if (keycode == ROT_RIGHT)
	{
		d->pa += 0.1;
		if (d->pa > 2 * PI)
			d->pa -= 2 * PI;
		d->pdX = cos(d->pa) * 5;
		d->pdY = sin(d->pa) * 5;
		d->posX += d->pdX;
		d->posY += d->pdY;
	}
	//draw_ray3d(d);
	draw_direction(d);
	return (0);
}
/*
void	draw_p_aftdir(t_data *c)//test implementation rotate P
{
	int y = d->pdY * 32;
	int x = d->pdX * 32;
	printf("drawp_aft %d\t%d\n", x, y);
	while (y < (d->pdY * 32) + 12)
	{
		while (x < (d->pdX * 32) + 12)
		{
			mlx_pixel_put(d->data->mlx_ptr, d->data->mlx_win,\
			x++, y, COLOR_P);
		}
		x = d->posX * 32;
		y++;
	}
}

void	calcul_direct(t_data *c)
{
	if (d->elem->E)
	{
		printf("av posX => %f\t pdY => %f\n", d->posX, d->posY);
		d->pa = PI;
		d->pdX = cos(d->pa);
		d->pdY = sin(d->pa);
		//d->posX += d->pdX;
		//d->posY += d->pdY;
		printf("ap posX => %f\t pdY => %f\n", d->pdX, d->pdY);
		draw_p_aftdir(c);
	}
}

*/

void	draw_direction(t_data *d)
{	
	//calcul_direct(d);

	printf("cos pdx => %f\tsin pdY %f\n", d->pdX, d->pdY);
	//d->posX + d->pdX + 2.5;	//player square mid
	//d->posY + d->pdY + 2.5;
//	printf("posX * 32 = %f\n x = %f\n", d->posX * 32, x);
	float lim;
	float y = d->posY + 2.5;
	float x = d->posX + 2.5;

	lim = 15;
	int i = 15;
	if (d->posX < 0)	
		lim = -15;
	while (i--)
	{
		mlx_pixel_put(d->mlx_ptr, d->mlx_win, x, y, COL_DIR_P);
		//x += d->pdX/5;
		y += d->pdY/5;
	}
	/*
	if (py < y)
	{	
		while (py < y)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, px++, py++, COL_DIR_P);
	}
	else 
		while (px < x)
			mlx_pixel_put(d->mlx_ptr, d->mlx_win, px++, py, COL_DIR_P);
	*/
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
	draw_direction(&data);
	//draw_ray3d(&data);
	//print_window(&data);
	//mlx_loop(data.mlx_ptr);
	mlx_key_hook(data.mlx_win, take_keycode, &data);
	mlx_loop(data.mlx_ptr);
	clean_all(&data, 0);
	return (0);
}
