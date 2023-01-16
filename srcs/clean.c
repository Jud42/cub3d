#include "cub3d.h"

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
	if ((*elem)->NO)
		free((*elem)->NO);
	if ((*elem)->SO)
		free((*elem)->SO);
	if ((*elem)->EA)
		free((*elem)->EA);
	if ((*elem)->WE)
		free((*elem)->WE);
	if (*elem)
		free(*elem);
}

void	clean_data(t_data **data)
{
	//if ((*data)->mlx_ptr)
	//	free((*data)->mlx_ptr);
	//if ((*data)->mlx_win)
	//	free((*data)->mlx_win);
	//if ((*data)->img)
	//	free((*data)->img);


}

void	clean_all(t_ray *ray, int flag)
{
	clean_element(&ray->elem);
	clean_data(&ray->data);
	clean_tab(ray->map, flag);
}
