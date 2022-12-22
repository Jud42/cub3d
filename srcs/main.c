#include "cub3d.h" 

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

int	main(int argc, char *argv[])
{
	t_data data;

	check_error_argument(argc, argv);
	if (init_all(&data, argv[1]))
		clean_all(&data, 1);
	print_wall(&data);
	draw_player(&data);
	ray_cast(&data);
	//draw_direction(&data, COL_DIR_P, 10, 10);
	mlx_key_hook(data.mlx_win, take_keycode, &data);
	mlx_loop(data.mlx_ptr);
	clean_all(&data, 0);
	return (0);
}
