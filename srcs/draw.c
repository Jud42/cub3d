/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:28:01 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:05 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_ray *r, t_text **t)
{
	*t = malloc(sizeof(t_text));
	if (!*t)
	{
		msg_error("malloc() in init_text()", 0);
		clean_all(r, EXIT);
	}
	if (r->side == 0 && r->raydir_x < 0.)
		(*t)->texdir = 0;
	if (r->side == 0 && r->raydir_x >= 0.)
		(*t)->texdir = 1;
	if (r->side == 1 && r->raydir_y < 0.)
		(*t)->texdir = 2;
	if (r->side == 1 && r->raydir_y >= 0.)
		(*t)->texdir = 3;
	if (r->side == 0)
		(*t)->wallx = r->posy + r->perpdwalldst * r->raydir_y;
	else
		(*t)->wallx = r->posx + r->perpdwalldst * r->raydir_x;
	(*t)->wallx -= floor((*t)->wallx);
}

void	draw_texture(t_ray *r, int x, int *y)
{
	t_text	*t;

	init_text(r, &t);
	t->step = 1.0 * r->data->texture[t->texdir].height / r->line_height;
	t->tex_x = (int)(t->wallx * (double)r->data->texture[t->texdir].width);
	if (r->side == 0 && r->raydir_x < 0.)
		t->tex_x = r->data->texture[t->texdir].width - t->tex_x - 1;
	if (r->side == 1 && r->raydir_y > 0.)
		t->tex_x = r->data->texture[t->texdir].width - t->tex_x - 1;
	t->texpos = (r->drawstart - r->data->screen_h / 2 + \
	r->line_height / 2) * t->step;
	while (*y <= r->drawend)
	{
		t->tex_y = (int)t->texpos & \
		(r->data->texture[t->texdir].height - 1);
		t->texpos += t->step;
		if (*y < r->data->screen_h && x < r->data->screen_w)
		{
			r->data->addr[*y * r->data->line_length / 4 + x] \
			= r->data->texture[t->texdir].addr[t->tex_y * \
			r->data->texture[t->texdir].height + t->tex_x];
		}
		(*y)++;
	}
	free(t);
}

void	ft_draw_column(t_ray *r)
{
	int	y;

	y = -1;
	while (++y < r->drawstart)
	{
		r->data->addr[y * r->data->line_length / 4 + r->x] = \
		r->elem->c;
	}
	if (y <= r->drawend)
		draw_texture(r, r->x, &y);
	while (y < r->data->screen_h)
	{
		r->data->addr[y * r->data->line_length / 4 + r->x] = \
		r->elem->f;
		y++;
	}
}
