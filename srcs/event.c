/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:28:19 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:22 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	left_or_right(t_ray *r)
{
	double	x;
	double	y;

	if (r->move.left)
	{
		x = r->posx + r->movespeed * r->pdy;
		y = r->posy - r->movespeed * r->pdx;
		if (r->map[(int)y][(int)x] == '0')
		{
			r->posx = x;
			r->posy = y;
		}
	}
	if (r->move.right)
	{
		x = r->posx - r->movespeed * r->pdy;
		y = r->posy + r->movespeed * r->pdx;
		if (r->map[(int)y][(int)x] == '0')
		{
			r->posx = x;
			r->posy = y;
		}
	}
}

void	rotation_right(t_ray *r)
{
	double	pa_cam;

	if (r->move.rot_right)
	{
		r->pa += 0.1;
		if (r->pa > PI * 2)
			r->pa -= PI * 2;
		r->pdx = cos(r->pa);
		r->pdy = sin(r->pa);
		pa_cam = r->pa + PI / 2;
		if (pa_cam > PI * 2)
			pa_cam -= PI * 2;
		r->planx = cos(pa_cam) * 0.66;
		r->plany = sin(pa_cam) * 0.66;
	}
}

void	rotation_left(t_ray *r)
{	
	double	pa_cam;

	if (r->move.rot_left)
	{
		r->pa -= 0.1;
		if (r->pa < 0.)
			r->pa += 2 * PI;
		r->pdx = cos(r->pa);
		r->pdy = sin(r->pa);
		pa_cam = r->pa + PI / 2;
		if (pa_cam < 0)
			pa_cam += PI * 2;
		r->planx = cos(pa_cam) * 0.66;
		r->plany = sin(pa_cam) * 0.66;
	}
}

void	up_or_down(t_ray *r)
{
	if (r->move.up)
	{
		if (r->map[(int)(r->posy + r->pdy * \
		r->movespeed)][(int)r->posx] == '0')
			r->posy += r->pdy * r->movespeed;
		if (r->map[(int)r->posy][(int)(r->posx + r->pdx * \
		r->movespeed)] == '0')
			r->posx += r->pdx * r->movespeed;
	}
	else if (r->move.down)
	{
		if (r->map[(int)(r->posy - r->pdy * \
		r->movespeed)][(int)r->posx] == '0')
			r->posy -= r->pdy * r->movespeed;
		if (r->map[(int)r->posy][(int)(r->posx - r->pdx * \
		r->movespeed)] == '0')
			r->posx -= r->pdx * r->movespeed;
	}
}

int	ft_keypress(int keycode, t_ray *r)
{
	if (keycode == UP)
		r->move.up = 1;
	else if (keycode == DOWN)
		r->move.down = 1;
	else if (keycode == ROT_LEFT)
		r->move.rot_left = 1;
	else if (keycode == ROT_RIGHT)
		r->move.rot_right = 1;
	else if (keycode == LEFT)
		r->move.left = 1;
	else if (keycode == RIGHT)
		r->move.right = 1;
	else if (keycode == CLOSE)
		ft_close(r);
	move(r);
	return (0);
}
