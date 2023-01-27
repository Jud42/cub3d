/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:09:31 by Blaze             #+#    #+#             */
/*   Updated: 2023/01/25 20:10:02 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_keypress, &ray);
	mlx_hook(data.mlx_win, 3, 1L << 1, ft_keyrelease, &ray);
	mlx_hook(data.mlx_win, 17, 1L << 0, ft_close, &ray);
	mlx_loop_hook(data.mlx_ptr, raycasting, &ray);
	mlx_loop(data.mlx_ptr);
	clean_all(&ray, 0);
	return (0);
}
