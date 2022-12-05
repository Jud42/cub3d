#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	init_element(t_elements **elem)
{
	*elem = malloc(sizeof(t_elements));
	if (!*elem)
	{
		printf("error: malloc() init_elem\n");
		return ;
	}
	(*elem)->NO = NULL;
    (*elem)->SO = NULL;
    (*elem)->WE = NULL;
    (*elem)->EA = NULL;
    (*elem)->F = 0;
    (*elem)->C = 0;
    (*elem)->N = 0;
    (*elem)->S = 0;
    (*elem)->E = 0;
    (*elem)->W = 0;
}

void    calcul_x_y(t_cube *c)
{
        int     y;
        int     x;

        if (!c->map)
                return ;
        x = 0;
        y = 0;
        while (c->map[y])
        {
                if (ft_strlen(c->map[y]) > x)
                        x = ft_strlen(c->map[y]);
                y++;
        }
        //mlx_get_screen_size(c->data->mlx_ptr, &c->data->width,\
	&c->data->height);
//      if (x * W_PIX < mlx->width)
        //c->data->width = x * W_PIX;
//      if ((y - c->start_map) * H_PIX < mlx->height)
		//c->data->height = y * H_PIX;
        c->data->width = 1000;
		c->data->height = 1000;
}


static int	init_data(t_cube *c)
{
	c->data = malloc(sizeof(t_data));
	if (!c->data)
		return (msg_error("malloc() init_data()\n"));
	c->data->mlx_ptr = mlx_init();
	calcul_x_y(c);
	/*--------------*///test t_img maybe dont need it
	t_img	*img = malloc(sizeof(t_img));
	if (!img)
		return (msg_error("malloc() struct img\n"));
	c->data->img = img;
	c->data->img->mlx_img = mlx_new_image(c->data->mlx_ptr, c->data->width, c->data->height);
	c->data->img->addr = mlx_get_data_addr(c->data->img->mlx_img, &c->data->img->bpp,\
	&c->data->img->line_len, &c->data->img->endian);
	/*----------------*/
	c->data->mlx_win = mlx_new_window(c->data->mlx_ptr, c->data->width, \
	c->data->height, "Hello world!");
	return (0);
}

int	init_all(t_cube *cube, char *file)
{
    cube->y = -1;
   	cube->x = 0;
   	cube->posY = 0;
   	cube->posX = 0;
	cube->data = NULL;
	cube->map = create_tab(file);
	init_element(&cube->elem);
	if (take_map(cube) || parse_map(cube))
		return (1);
	else if (init_data(cube))
		return (1);
	printf("posX => %f\tposY => %f\n", cube->posX, cube->posY);
	/*int i = -1;
	while (cube->map[++i])
		printf("%s\n", cube->map[i]);
	exit (0);*/
	return (0);
}
