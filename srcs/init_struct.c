#include "cub3d.h"

static int      init_img(char **texture, t_data *d, t_img *t)
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

int     init_texture(t_ray *r) //free(malloc)
{
        if (init_img(&r->elem->NO, r->data, &r->data->texture[0]))
                return (1);
        if (init_img(&r->elem->SO, r->data, &r->data->texture[1]))
                return (1);
        if (init_img(&r->elem->EA, r->data, &r->data->texture[2]))
                return (1);
        if (init_img(&r->elem->WE, r->data, &r->data->texture[3]))
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
/*-------------------*/

void    calcul_screen(t_data *d)
{
        mlx_get_screen_size(d->mlx_ptr, &d->screen_w, &d->screen_h);
	if (SCREEN_WIDTH < d->screen_w)
        	d->screen_w = SCREEN_WIDTH;
	if (SCREEN_HEIGHT < d->screen_h)
		d->screen_h = SCREEN_HEIGHT;
}

static int	init_mlx(t_ray *r)
{
	r->data->mlx_ptr = mlx_init();
	if (!r->data->mlx_ptr)
		return (msg_error("mlx_ptr", 0));
	calcul_screen(r->data);
	r->data->mlx_win = mlx_new_window(r->data->mlx_ptr, \
	r->data->screen_w, r->data->screen_h, "cub3d");
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
	r->elem->NO = NULL;
    	r->elem->SO = NULL;
    	r->elem->WE = NULL;
    	r->elem->EA = NULL;
    	r->elem->F = 0;
    	r->elem->C = 0;
}

int	init_all(t_ray *ray, char *file)
{
   	ray->y = -1;
   	ray->x = 0;
	ray->pa = -1;
	ray->map = create_tab(file);
	init_element(ray);
	ray->planX = 0;
	ray->planY = 0;
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
	ray->movespeed = 0.1;
	ray->rotspeed = 0.3;
	return (0);
}
