#include "cub3d.h" 

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

int	main(int argc, char *argv[])
{
	t_ray	ray;
	t_data	data;

	check_error_argument(argc, argv);
	ray.data = &data;
	if (init_all(&ray, argv[1]))
		clean_all(&ray, 1);
	if (init_texture(&ray))
		clean_all(&ray, 1);
	//print_wall(&ray);
	//draw_player(&data);
	//draw_direction(&data, COL_DIR_P, 10, 10);
	//mlx_mouse_hook(data.mlx_win, exit, &ray);
	//raycasting(&ray);
	mlx_loop_hook(data.mlx_ptr, raycasting, &ray);
	mlx_loop(data.mlx_ptr);
	clean_all(&ray, 0);
	return (0);
}
