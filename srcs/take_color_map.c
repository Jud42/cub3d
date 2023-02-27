/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_color_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:29:44 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/02 22:36:16 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	eno(char **tab_rgb, char **str_hexe)
{
	free(*str_hexe);
	clean_tab(tab_rgb, 0);
	return (msg_error("value of F&C must be between 0,255", 0));
}

static int	take_rgb_hexe(char **tab_rgb, char **str_hexe)
{
	char	*tmp;
	char	*hex_tmp;
	int		i;

	*str_hexe = ft_strdup("0x");
	if (!*str_hexe)
	{
		clean_tab(tab_rgb, 0);
		return (msg_error("malloc(): in take_color", 0));
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(tab_rgb[i]) < 0 || \
			ft_atoi(tab_rgb[i]) > 255)
			return (eno(tab_rgb, str_hexe));
		tmp = conv_hexe(ft_atoi(tab_rgb[i]));
		hex_tmp = *str_hexe;
		*str_hexe = ft_strjoin(hex_tmp, tmp);
		free(hex_tmp);
		free(tmp);
	}
	clean_tab(tab_rgb, 0);
	return (0);
}

static int	check_digit(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (!ft_isdigit(tab[i][j]))
				return (1);
	}
	return (0);
}

static int	create_tab_rgb(char *line, char ***tab_ret)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab || !tab[1] || tab[2] != NULL)
	{
		if (tab)
			clean_tab(tab, 0);
		return (msg_error("format color not valid", 0));
	}
	*tab_ret = ft_split(tab[1], ',');
	clean_tab(tab, 0);
	if (!*tab_ret || !(*tab_ret)[1] || !(*tab_ret)[2] \
		|| (*tab_ret)[3] || check_digit(*tab_ret))
	{
		if (*tab_ret)
			clean_tab(*tab_ret, 0);
		return (msg_error("format color not valid", 0));
	}
	return (0);
}

int	take_color(char *line, t_elements *elem)
{
	int		i;
	char	c;
	char	**tab_rgb;
	char	*hexe_rgb;

	i = -1;
	while (line[++i] && line[i] == ' ')
		;
	c = line[i];
	if (line[i] == 'F' || (line[i] == 'C' && line[i + 1] == ' '))
	{
		if (create_tab_rgb(line, &tab_rgb))
			return (1);
		if (take_rgb_hexe(tab_rgb, &hexe_rgb))
			return (1);
		if (c == 'F')
			elem->f = ft_atoi_hexe(hexe_rgb);
		else
			elem->c = ft_atoi_hexe(hexe_rgb);
		free(hexe_rgb);
		return (0);
	}
	return (msg_error("unrecognized identifier", 0));
}
