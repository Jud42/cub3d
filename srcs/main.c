#include "cub3d.h" 
/*
    North (N): 0° = 360°
    East (E): 90°
    South (S): 180°
    West (W): 270°
 */

void	draw_rotation(t_cube *c)
{
	/* //direction initial
	if (c->elem->N)
		;//dir 2 pi
	else if (c->elem->S)
		;//pi
	else if (c->elem->E)
		;// 2 pi / 2
	else (c->elem->W)
		;// 3 pi / 2
	*/
}

void	draw_direction(t_cube *c)
{	
	int y = c->posY * 32;
	int x = c->posX * 32 + 6;
	while (y > 32)
	{
			mlx_pixel_put(c->data->mlx_ptr, c->data->mlx_win,\
			x, y--, COL_DIR_P);
	}
}

void	draw_player(t_cube *c)//test implementation rotate P
{
	int y = c->posY * 32;
	int x = c->posX * 32;
	printf("%d\t%d\n", x, y);
	while (y < (c->posY * 32) + 12)
	{
		while (x < (c->posX * 32) + 12)
		{
			mlx_pixel_put(c->data->mlx_ptr, c->data->mlx_win,\
			x++, y, COLOR_P);
		}
		x = c->posX * 32;
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

void	print_wall(t_cube *c)
{
	if (c->elem->NO)
		init_wall(&c->elem->NO, &c->data->mlx_ptr);
	if (c->elem->SO)
		init_wall(&c->elem->SO, &c->data->mlx_ptr);
	if (c->elem->EA)
		init_wall(&c->elem->EA, &c->data->mlx_ptr);
	if (c->elem->WE)
		init_wall(&c->elem->WE, &c->data->mlx_ptr);
	c->y = 0;
	while (c->map[c->y])
	{
		c->x = -1;
		while (c->map[c->y][++c->x])
		{
			if (c->map[c->y][c->x] == '1')
				mlx_put_image_to_window(c->data->mlx_ptr, c->data->mlx_win, c->elem->EA, c->x * 32, c->y * 32);
		}
		c->y++;
	}
}

int	main(int argc, char *argv[])
{
	t_cube cube;

	check_error_argument(argc, argv);
	if (init_all(&cube, argv[1]))
		clean_all(&cube, 1);
	print_wall(&cube);
	draw_player(&cube);
	draw_direction(&cube);
	//print_window(&cube);
	//mlx_loop(cube.data->mlx_ptr);
	mlx_loop(cube.data->mlx_ptr);
	clean_all(&cube, 0);
	return (0);
}
