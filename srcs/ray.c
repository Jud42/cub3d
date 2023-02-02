/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:28:45 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:48 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

void	init_dir_and_plancam(t_ray *r)
{
	r->planx = 0;
	r->plany = 0;
	r->pdx = cos(r->pa);
	r->pdy = sin(r->pa);
	if (r->pos == 'N')
		r->planx = 0.66;
	if (r->pos == 'S')
		r->planx = -0.66;
	if (r->pos == 'E')
		r->plany = 0.66;
	if (r->pos == 'W')
		r->plany = -0.66;
}

static void	ft_dda(t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedst_x < r->sidedst_y)
		{
			r->sidedst_x += r->deltadst_x;
			r->mapx += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedst_y += r->deltadst_y;
			r->mapy += r->step_y;
			r->side = 1;
		}
		if (r->map[r->mapy][r->mapx] == '1' || \
		r->map[r->mapy][r->mapx] == 32)
			r->hit = 1;
	}
}

static void	init_step_side(t_ray *r)
{
	if (r->raydir_x < 0.)
	{
		r->step_x = -1;
		r->sidedst_x = (r->posx - r->mapx) * r->deltadst_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedst_x = (r->mapx + 1.0 - r->posx) * r->deltadst_x;
	}
	if (r->raydir_y < 0.)
	{
		r->step_y = -1;
		r->sidedst_y = (r->posy - r->mapy) * r->deltadst_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedst_y = (r->mapy + 1.0 - r->posy) * r->deltadst_y;
	}
}

static void	init_deltax_y(t_ray *r)
{
	r->hit = 0;
	r->perpdwalldst = 0.;
	r->camera_x = 2 * r->x / (double)r->data->screen_w - 1;
	r->raydir_x = r->pdx + r->planx * r->camera_x;
	r->raydir_y = r->pdy + r->plany * r->camera_x;
	r->mapx = (int)r->posx;
	r->mapy = (int)r->posy;
	if (r->raydir_y == 0.)
		r->deltadst_x = 0.;
	else if (r->raydir_x == 0.)
		r->deltadst_x = 1.;
	else
	{
		r->deltadst_x = sqrt(1 + (r->raydir_y * r->raydir_y) \
		/ (r->raydir_x * r->raydir_x));
	}
	if (r->raydir_x == 0.)
		r->deltadst_y = 0;
	else if (r->raydir_y == 0.)
		r->deltadst_y = 1.;
	else
	{
		r->deltadst_y = sqrt(1 + (r->raydir_x * r->raydir_x) \
		/ (r->raydir_y * r->raydir_y));
	}
}

int	raycasting(t_ray *r)
{
	r->x = -1;
	while (++r->x < r->data->screen_w)
	{
		init_deltax_y(r);
		init_step_side(r);
		ft_dda(r);
		if (r->side == 0)
			r->perpdwalldst = ((double)r->mapx - r->posx + \
			(1 - (double)r->step_x) / 2) / r->raydir_x;
		else
			r->perpdwalldst = ((double)r->mapy - r->posy + \
			(1 - (double)r->step_y) / 2) / r->raydir_y;
		r->line_height = (int)(r->data->screen_h / r->perpdwalldst);
		r->drawstart = -r->line_height / 2 + r->data->screen_h / 2;
		if (r->drawstart < 0)
			r->drawstart = 0;
		r->drawend = r->line_height / 2 + r->data->screen_h / 2;
		if (r->drawend >= r->data->screen_h || r->drawend < 0)
			r->drawend = r->data->screen_h - 1;
		ft_draw_column(r);
	}
	mlx_put_image_to_window(r->data->mlx_ptr, r->data->mlx_win, \
	r->data->img, 0, 0);
	return (0);
}
