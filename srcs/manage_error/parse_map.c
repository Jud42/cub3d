/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:15:03 by Blaze             #+#    #+#             */
/*   Updated: 2023/02/02 22:43:06 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_space(t_ray *r)
{
	int	y_tmp;

	if (r->map[r->y][r->x - 1] != '1')
		return (msg_error("wall not close", 0));
	while (r->map[r->y][r->x] && r->map[r->y][r->x] == ' ')
	{
		y_tmp = r->y;
		while (y_tmp-- > 0 && r->x < (int)ft_strlen(r->map[y_tmp]) \
			&& r->map[y_tmp][r->x] != '1')
			if (r->map[y_tmp][r->x] != ' ' && r->map[y_tmp][r->x] != '1')
				return (msg_error("wall not close", 0));
		y_tmp = r->y;
		while (r->map[++y_tmp] && r->map[y_tmp][r->x] != '1'\
			&& r->x < (int)ft_strlen(r->map[y_tmp]))
			if (r->map[y_tmp][r->x] != ' ' && r->map[y_tmp][r->x] != '1')
				return (msg_error("wall not close", 0));
		++r->x;
	}
	if (r->map[r->y][r->x] && r->map[r->y][r->x] != '1')
		return (msg_error("wall not close", 0));
	return (0);
}

static int	check_position(t_ray *r)
{
	char	c;

	c = r->map[r->y][r->x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (r->pa > -1)
			return (msg_error("multiple position identify", 0));
		else if (c == 'N')
			r->pa = PI * 3 / 2;
		else if (c == 'S')
			r->pa = PI / 2;
		else if (c == 'E')
			r->pa = PI;
		else
			r->pa = 0.0;
		r->posy = (double)r->y + 0.5;
		r->posx = (double)r->x + 0.5;
		r->map[r->y][r->x] = '0';
		r->pos = c;
		return (0);
	}
	if (c != '1' && c != '0' && c != ' ')
		return (msg_error("caracter forbidden in map", 0));
	return (0);
}

static int	check_char(t_ray *r)
{
	if (r->map[r->y][ft_strlen(r->map[r->y]) - 1] != '1'\
		&& r->map[r->y][ft_strlen(r->map[r->y]) - 1] != ' ')
	{
		ft_putchar_fd(r->map[r->y][ft_strlen(r->map[r->y]) - 1], 1);
		return (msg_error("wall not respected", 0));
	}
	while (r->map[r->y][++(r->x)])
	{
		if (r->y == 0 && r->map[r->y][r->x] != '1' \
			&& (r->map[r->y][r->x] != ' ' || !r->map[r->y + 1]) \
			&& r->map[r->y][r->x] != '1' && r->map[r->y][r->x] != ' ')
		{
			ft_putchar_fd(r->map[r->y][r->x], 1);
			return (msg_error("wall not respected", 0));
		}
		else if (check_position(r))
			return (1);
		else if (r->map[r->y][r->x] == ' ')
			if (check_space(r))
				return (1);
	}
	return (0);
}

int	parse_map(t_ray *r)
{
	r->y = -1;
	r->x = 0;
	while (r->map[++r->y])
	{
		while (r->map[r->y][r->x])
		{
			while (r->map[r->y][r->x] == ' ')
				r->x++;
			if (r->map[r->y][r->x] && r->map[r->y][r->x] != '1')
				return (msg_error("map :( not valid", 0));
			if (check_char(r))
				return (1);
		}
		r->x = 0;
	}
	if (r->pa == -1)
		return (msg_error("no Player", 0));
	fill_map(r);
	return (0);
}
