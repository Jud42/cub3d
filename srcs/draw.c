#include "../includes/cub3d.h"

void	init_text(t_ray *r, t_text **t)
{
	*t = malloc(sizeof(t_text));
	if (!*t)
	{
		msg_error("malloc() in init_text()", 0);
		clean_all(r, EXIT);
	}
	if (r->side == 0 && r->raydirX < 0.)
		(*t)->texdir = 0;
	if (r->side == 0 && r->raydirX >= 0.)
		(*t)->texdir = 1;
	if (r->side == 1 && r->raydirY < 0.)
		(*t)->texdir = 2;
	if (r->side == 1 && r->raydirY >= 0.)
		(*t)->texdir = 3;
	if (r->side == 0)
		(*t)->wallX = r->posY + r->perpdwalldst * r->raydirY;
	else
		(*t)->wallX = r->posX + r->perpdwalldst * r->raydirX;
	(*t)->wallX -= floor((*t)->wallX);
}

void	draw_texture(t_ray *r, int x, int *y)
{
	t_text *t;

	init_text(r, &t);
	t->step = 1.0 * r->data->texture[t->texdir].height / r->lineHeight;
	t->texX = (int)(t->wallX * (double)r->data->texture[t->texdir].width);
	if (r->side == 0 && r->raydirX < 0.) 
		t->texX = r->data->texture[t->texdir].width - t->texX - 1;
	if (r->side == 1 && r->raydirY > 0.)
		t->texX = r->data->texture[t->texdir].width - t->texX - 1;
	t->texpos = (r->drawstart - r->data->screen_h / 2 + \
	r->lineHeight / 2) * t->step;
	while (*y <= r->drawend)
	{
		t->texY = (int)t->texpos & \
		(r->data->texture[t->texdir].height - 1);
		t->texpos += t->step;
		if (*y < r->data->screen_h && x < r->data->screen_w)
		{
			r->data->addr[*y * r->data->line_length / 4  + x] \
			= r->data->texture[t->texdir].addr[t->texY * \
			r->data->texture[t->texdir].height + \
			t->texX];
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
		r->elem->C;
	}
	if (y <= r->drawend)
		draw_texture(r, r->x, &y);
	while (y < r->data->screen_h)
	{
		r->data->addr[y * r->data->line_length / 4 + r->x] = \
		r->elem->F;
		y++;
	}
}
