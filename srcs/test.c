#include "cub3d.h" 

void	calcul_x_y(t_cube *c, t_data *mlx)
{
	int	y;
	int	x;
	
	if (!c->tab)
		return ;
	x = 0;
	y = c->start_map;
	while (c->tab[y])
	{
		if (ft_strlen(c->tab[y]) > x)
			x = ft_strlen(c->tab[y]);
		y++;
	}
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->width, &mlx->height);
	if (x * W_PIX < mlx->width)
		mlx->width = x * W_PIX;
	if ((y - c->start_map) * H_PIX < mlx->height)
		mlx->height = (y - c->start_map) * H_PIX;
}

void	print_window(t_cube *c, t_data *mlx)
{
	int	x;
	int	y;
	
	mlx->mlx_ptr = mlx_init();
	calcul_x_y(c, mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, \
	mlx->height, "Hello world!");
	mlx_loop(mlx->mlx_ptr);
	c->mlx = mlx;
}

int	main(int argc, char *argv[])
{
	t_cube cube;
	t_elements elem;
	t_data	mlx;

	check_error_argument(argc, argv);
	cube.tab = create_tab(argv[1]);
	init_all(&cube, &elem);
	parse_map(&cube, &elem);
	print_window(&cube, &mlx);
	clean_all(&cube, 0);
}
