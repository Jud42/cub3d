/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:21:46 by Blaze             #+#    #+#             */
/*   Updated: 2023/02/02 22:58:06 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	init_img(char **texture, t_data *d, t_img *t)
{
	t->img = mlx_xpm_file_to_image(d->mlx_ptr, *texture, \
	&t->width, &t->height);
	if (!t->img)
		return (msg_error("path xpm not found", 0));
	t->addr = (int *)mlx_get_data_addr(t->img, &t->bpp, \
	&t->line_length, &t->endian);
	if (!t->addr)
		return (msg_error("mlx_get_addr", 0));
	return (0);
}

int	init_texture(t_ray *r)
{
	if (init_img(&r->elem->no, r->data, &r->data->texture[0]))
		return (1);
	if (init_img(&r->elem->so, r->data, &r->data->texture[1]))
		return (1);
	if (init_img(&r->elem->ea, r->data, &r->data->texture[2]))
		return (1);
	if (init_img(&r->elem->we, r->data, &r->data->texture[3]))
		return (1);
	r->data->img = mlx_new_image(r->data->mlx_ptr, \
	r->data->screen_w, r->data->screen_h);
	if (!r->data->img)
		return (msg_error("create img mlx_new_img()", 0));
	r->data->addr = (int *)mlx_get_data_addr(r->data->img, \
	&r->data->bpp, &r->data->line_length, &r->data->endian);
	if (!r->data->addr)
		return (msg_error("mlx_get_addr in init_texture()", 0));
	return (0);
}

static int	init_mlx(t_ray *r)
{
	r->data->img = NULL;
	r->data->mlx_ptr = mlx_init();
	r->data->screen_w = SCREEN_WIDTH;
	r->data->screen_h = SCREEN_HEIGHT;
	r->data->mlx_win = mlx_new_window(r->data->mlx_ptr, \
	r->data->screen_w, r->data->screen_h, "Cub3D");
	if (!r->data->mlx_win)
		return (msg_error("mlx_win", 0));
	return (init_texture(r));
}

static void	init_element(t_ray *r)
{
	r->elem = malloc(sizeof(t_elements));
	if (!r->elem)
	{
		msg_error("malloc() init_elem", 0);
		clean_tab(r->map, EXIT);
	}
	r->elem->no = NULL;
	r->elem->so = NULL;
	r->elem->we = NULL;
	r->elem->ea = NULL;
	r->elem->f = 0;
	r->elem->c = 0;
	init_move(r);
}

int	init_all(t_ray *ray, char *file)
{
	ray->y = -1;
	ray->x = 0;
	ray->pa = -1;
	ray->map = create_tab(file);
	init_element(ray);
	ray->planx = 0;
	ray->plany = 0;
	if (take_map(ray) || parse_map(ray))
	{
		clean_element(&ray->elem);
		clean_tab(ray->map, EXIT);
	}
	else if (init_mlx(ray))
		return (1);
	init_dir_and_plancam(ray);
	ray->time = 0;
	ray->oldtime = 0;
	ray->movespeed = 0.2;
	ray->rotspeed = 0.3;
	return (0);
}
