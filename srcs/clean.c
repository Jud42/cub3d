/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:27:40 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/02 20:27:45 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_image(t_ray *r)
{
	int	y;
	int	x;

	x = -1;
	while (++x < r->data->screen_w)
	{
		y = -1;
		while (++y < r->data->screen_w)
			r->data->addr[y * r->data->line_length / 4 + x] = 0;
	}
}

void	clean_tab(char **tab, int flag)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
	if (flag == EXIT)
		exit(EXIT_FAILURE);
}

void	clean_element(t_elements **elem)
{
	if ((*elem)->no)
		free((*elem)->no);
	if ((*elem)->so)
		free((*elem)->so);
	if ((*elem)->ea)
		free((*elem)->ea);
	if ((*elem)->we)
		free((*elem)->we);
	if (*elem)
		free(*elem);
}

void	clean_data_mlx(t_data **data)
{
	if ((*data)->img)
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
	if ((*data)->mlx_win)
		mlx_destroy_window((*data)->mlx_ptr, (*data)->mlx_win);
}

void	clean_all(t_ray *ray, int flag)
{
	clean_element(&ray->elem);
	clean_data_mlx(&ray->data);
	clean_tab(ray->map, flag);
}
