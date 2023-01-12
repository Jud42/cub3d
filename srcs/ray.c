#include "cub3d.h" 

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

void	init_dir_and_plancam(t_ray *r)
{
	r->planX = 0;
	r->planY = 0;
	r->pdX = cos(r->pa);
	r->pdY = sin(r->pa);
 	if (r->pos == 'N')
		r->planX = 0.66;
 	if (r->pos == 'S')
		r->planX = -0.66;
 	if (r->pos == 'E')
		r->planY = -0.66;
 	if (r->pos == 'W')
		r->planY = 0.66;
}

static void	ft_dda(t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedstX < r->sidedstY)
		{
			r->sidedstX += r->deltadstX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sidedstY += r->deltadstY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (r->map[r->mapY][r->mapX] == '1') //30 = '0'
			r->hit = 1;
	}
}

static void	init_step_side(t_ray *r)
{
	if (r->raydirX < 0.)
	{
		r->stepX = -1;
		r->sidedstX = (r->posX - r->mapX) * r->deltadstX;
	}
	else
	{
		r->stepX = 1;
		r->sidedstX = (r->mapX + 1.0 - r->posX) * r->deltadstX;
	}
	if (r->raydirY < 0.)
	{
		r->stepY = -1;
		r->sidedstY = (r->posY - r->mapY) * r->deltadstY;
	}
	else
	{
		r->stepY = 1;
		r->sidedstY = (r->mapY + 1.0 - r->posY) * r->deltadstY;
	}
}


static void	init_deltax_y(t_ray *r)
{
	r->hit = 0;
	r->perpdwalldst = 0;
	r->cameraX = 2 * r->x / (double)r->data->screen_w - 1;
	r->raydirX = r->pdX + r->planX * r->cameraX; // 5;
	r->raydirY = r->pdY + r->planY * r->cameraX; // 5;
	r->mapX = (int)r->posX;
	r->mapY = (int)r->posY;
	if (r->raydirY == 0.)
		r->deltadstX = 0;
	else if (r->raydirX == 0.)
		r->deltadstX = 1;
	else
	{
		r->deltadstX = sqrt(1 + (r->raydirY * r->raydirY) \
		/ (r->raydirX * r->raydirX));
	}
	if (r->raydirX == 0.)
		r->deltadstY = 0;
	else if (r->raydirY == 0.)
		r->deltadstY = 1;
	else
	{
		r->deltadstY = sqrt(1 + (r->raydirX * r->raydirX) \
		/ (r->raydirY * r->raydirY));
	}
}

int	raycasting(t_ray *r)
{
	r->x = -1;	
	while(++r->x < r->data->screen_w)
	{
		init_deltax_y(r);
		init_step_side(r);
		ft_dda(r);
		if (r->side == 0)
		{
			//r->perpdwalldst = (r->sidedstX - r->deltadstX);
			r->perpdwalldst = ((double)r->mapX - r->posX + \
			(1 - (double)r->stepX) / 2) / r->raydirX;
		}
		else 
		{
			//r->perpdwalldst = (r->sidedstY - r->deltadstY);
			r->perpdwalldst = ((double)r->mapY - r->posY + \
			(1 - (double)r->stepY) / 2) / r->raydirY;
		}
		r->lineHeight = (int) (r->data->screen_h / r->perpdwalldst);
		r->drawstart = -r->lineHeight / 2 + r->data->screen_h / 2;
		if (r->drawstart < 0)
			r->drawstart = 0;
		r->drawend = r->lineHeight / 2 + r->data->screen_h / 2;
		if (r->drawend >= r->data->screen_h || r->drawend < 0)
			r->drawend = r->data->screen_h - 1;
		ft_draw_column(r);
	}
	mlx_put_image_to_window(r->data->mlx_ptr, r->data->mlx_win, \
	r->data->img, 0, 0);
	return (0);
}
