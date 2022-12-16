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
}

void    calcul_x_y(t_data *d)
{
        int     y;
        int     x;

        if (!d->map)
                return ;
        x = 0;
        y = 0;
        while (d->map[y])
        {
                if (ft_strlen(d->map[y]) > x)
                        x = ft_strlen(d->map[y]);
                y++;
        }
        //mlx_get_screen_size(d->mlx_ptr, &d->width,\
	&d->height);
//      if (x * W_PIX < d->width)
        //d->width = x * W_PIX;
//      if ((y - c->start_map) * H_PIX < d->height)
		//d->height = y * H_PIX;
        d->width = 1000;
	d->height = 1000;
}


static int	init_mlx(t_data **data)
{
	t_data *d;

	d = *data;
	d->mlx_ptr = mlx_init();
	calcul_x_y(d);
	/*--------------*///test t_img maybe dont need it
	t_img	*img = malloc(sizeof(t_img));
	if (!img)
		return (msg_error("malloc() struct img\n"));
	d->img = img;
	d->img->mlx_img = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->img->addr = mlx_get_data_addr(d->img->mlx_img, &d->img->bpp,\
	&d->img->line_len, &d->img->endian);
	/*----------------*/
	d->mlx_win = mlx_new_window(d->mlx_ptr, d->width, \
	d->height, "Hello world!");
	return (0);
}

int	init_all(t_data *data, char *file)
{
    data->y = -1;
   	data->x = 0;
   	data->posY = 0.0;
   	data->posX = 0.0;
	data->pa = -1;
	data->map = create_tab(file);
	init_element(&data->elem);
	if (take_map(data) || parse_map(data))
		return (1);
	else if (init_mlx(&data))
		return (1);
	data->pdX = cos(data->pa) * 5;
	data->pdY = sin(data->pa) * 5;
	/*int i = -1;
	while (data->map[++i])
		printf("%s\n", data->map[i]);
	exit (0);*/
	return (0);
}
