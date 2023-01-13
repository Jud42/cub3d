#include "../includes/cub3d.h"

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

void	textures_init(char *paths[10])
{
    int	i;

    i = -1;
    while (++i < 10)
        paths[i] = NULL;
}

int	init_texture(t_data *data)
{
    int	i;

    i = -1;
    while (++i < 7 && data->paths[i + 2])
    {
        data->textures[i].img = mlx_xpm_file_to_image(data->mlx,
                                                      data->paths[i + 2], &data->textures[i].h, &data->textures[i].w);
        if (data->textures[i].img == NULL)
            return (1);
        data->textures[i].addr = mlx_get_data_addr(data->textures[i].img,
                                                   &data->textures[i].bpp,
                                                   &data->textures[i].line_len, &data->textures[i].endian);
        data->textures[i].frame = 0;
    }
    return (0);
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
}

static int	init_mlx(t_data **data)
{
	t_data *d;

	d = *data;
	d->mlx = mlx_init();
	calcul_x_y(d);
	d->view3d.img = mlx_new_image(d->mlx, WIN_W, WIN_H);
	d->view3d.addr = mlx_get_data_addr(d->view3d.img, &d->view3d.bpp,\
	&d->view3d.line_len, &d->view3d.endian);
	/*----------------*/
	d->win = mlx_new_window(d->mlx, WIN_W, \
	WIN_H, "Cub3D");
	return (0);
}

int	init_all(t_data *data, char *file)
{
    data->player.dir.y = -1;
   	data->player.dir.x = 0;
   	data->player.pos.y = 22.0;
   	data->player.pos.x = 12.0;
	data->player.angle = -1.0;
	data->map = create_tab(file);
	//init_element(data->player.wall_type);
	if (take_map(data) || parse_map(data))
		return (1);
	else if (init_mlx(&data))
		return (1);
	return (0);
}
