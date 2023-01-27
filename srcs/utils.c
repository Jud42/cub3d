/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:48:45 by Blaze             #+#    #+#             */
/*   Updated: 2023/01/25 22:25:23 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mapx_y(t_ray *r)
{
	int	i;

	i = 0;
	r->mapx = ft_strlen(r->map[i]);
	while (r->map[++i])
		if (ft_strlen(r->map[i]) > r->mapx)
			r->mapx = ft_strlen(r->map[i]);
	r->mapy = i;
}

int	ft_atoi_hexe(const char *str)
{
	int		i;
	int		ret;
	int		len;
	int		value;
	char	c;

	i = 0;
	ret = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		c = str[i];
		value = 0;
		if (c >= '0' && c <= '9')
				value = c - '0';
		else if (c >= 'a' && c <= 'f')
				value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
				value = c - 'A' + 10;
		ret += value * pow(16, len - i - 1);
		i++;
	}
	return (ret);
}

int	nb_line_hex(int n)
{
	int	i;

	i = 0;
	if (n <= 15 && n >= 0)
		i = 1;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	if (i == 1)
		i++;
	return (i);
}

char	*conv_hexe(int n)
{
	char	*s;
	char	*ret;	
	int		i;
	int		j;

	i = nb_line_hex(n);
	j = i;
	s = "0123456789ABCDEF\0";
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	if (n <= 15 && n >= 0)
		ret[0] = '0';
	if (n == 0)
		ret[1] = '0';
	while (n != 0)
	{
		if (n >= 16)
			ret[--i] = s[n % 16];
		else
			ret[--i] = s[n];
		n /= 16;
	}
	ret[j] = '\0';
	return (ret);
}

void	fill_map(t_ray *r)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	init_mapx_y(r);
	while (r->map[i])
	{
		if (ft_strlen(r->map[i]) < r->mapx)
		{
			j = -1;
			s = malloc(sizeof(char) * r->mapx + 1);
			while (r->map[i][++j])
				s[j] = r->map[i][j];
			while (j < r->mapx)
				s[j++] = 32;
			s[j] = '\0';
			free(r->map[i]);
			r->map[i] = s;
		}
		i++;
	}
}
