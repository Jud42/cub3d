#include "../includes/cub3d.h"
/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

void	my_mlx_pixel_put(t_img *t, int x, int y, int color)
{
    int	*dst;

    dst = t->addr + (y * t->line_length + x * (t->bpp / 8));
    *(unsigned int*)dst = color;
}

void	init_text(t_ray *r, t_text **t)
{
    *t = malloc(sizeof(t_text));
    if (!*t)
        ;//
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

void	draw_texture(t_ray *r, int x, int y)
{
    t_text *t;

    y = r->drawstart - 1;
    init_text(r, &t);
    t->step = 1.0 * r->data->texture[0].height / r->lineHeight;
    t->texX = (int)(t->wallX * (double)r->data->texture[t->texdir].width);
    if (r->side == 0 && r->raydirX > 0.)
        t->texX = r->data->texture[t->texdir].width - t->texX - 1;
    if (r->side == 1 && r->raydirY < 0.)
        t->texX = r->data->texture[t->texdir].width - t->texX - 1;
    t->texpos = (r->drawstart - r->data->screen_h / 2 + \
	r->lineHeight / 2) * t->step;
    while (++y <= r->drawend)
    {
        t->texY = (int)t->texpos & \
		(r->data->texture[t->texdir].height - 1);
        t->texpos += t->step;
        if (y < r->data->screen_h && x < r->data->screen_w)
        {
            r->data->addr[y * r->data->line_length / 4  + x] \
			= r->data->texture[t->texdir].addr[t->texY * \
			r->data->texture[t->texdir].line_length / 4 + \
			t->texX];
        }
    }
    free(t);// a la fin
}

void	ft_draw_column(t_ray *r)
{
    int	y;

    y = -1;
    while (++y < r->drawstart)
    {
        r->data->addr[y * r->data->line_length / 4 + r->x] = \
		0x00FF0000; //r->elem->c in this place
    }
    if (y <= r->drawend)
        draw_texture(r, r->x, y);
    y = r->drawend - 1;
    while (++y < r->data->screen_h)
    {
        r->data->addr[y * r->data->line_length / 4 + r->x] = \
		0x000000FF; //r->elem->f in this place
    }
}