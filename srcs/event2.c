/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:05:09 by Blaze             #+#    #+#             */
/*   Updated: 2023/01/25 20:43:35 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close(t_ray *r)
{
	clean_all(r, 0);
	exit (0);
}

void	move(t_ray *r)
{
	up_or_down(r);
	left_or_right(r);
	rotation_right(r);
	rotation_left(r);
}

int	ft_keyrelease(int keycode, t_ray *r)
{
	if (keycode == UP)
		r->move.up = 0;
	if (keycode == DOWN)
		r->move.down = 0;
	if (keycode == ROT_LEFT)
		r->move.rot_left = 0;
	if (keycode == ROT_RIGHT)
		r->move.rot_right = 0;
	if (keycode == LEFT)
		r->move.left = 0;
	if (keycode == RIGHT)
		r->move.right = 0;
	return (0);
}

int	nb_line_tab(char *file)
{
	char	*s;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		msg_error("error open() file", EXIT);
	s = get_next_line(fd);
	if (!s)
		msg_error("error Empty file", EXIT);
	ret = 0;
	while (s != NULL)
	{
		ret++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (ret);
}
