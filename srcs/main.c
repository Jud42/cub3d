#include "cub3d.h" 
/*
void	put_sol_color(t_data *mlx)
{
	//1366
	//768
	int	y;
	int	x;
	int	width;
	int	height;

	y = -1;
	mlx->img.mlx_img = mlx_new_image();
	while (++y < 768)
	{
		x = 0;
		while (++x < 1366)
			mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, \
			x++, y, 0x00990000);
	}
}
*/

void	init_wall(void **texture, void **mlx_ptr)
{
	int	width;
	int	height;
	void 	*path;
	
	printf("%s\n", (char*)*texture);
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
/*	while (c->y)
	{
		c->x = -1;
		while (c->map[c->y][++c->x])
		{
			if (c->map[c->y][c->x] == '1')
				mlx_put_image_to_window(c->data->mlx_ptr, c->data->mlx_win, c->elem->NO, c->data->width, c->data->height);
		}
		c->y++;
	}*/
}

int	main(int argc, char *argv[])
{
	t_cube cube;

	check_error_argument(argc, argv);
	if (init_all(&cube, argv[1]))
		clean_all(&cube, 1);
	print_wall(&cube);
	//print_window(&cube);
	//mlx_loop(cube.data->mlx_ptr);
	clean_all(&cube, 0);
	return (0);
}
