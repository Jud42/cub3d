#include "../includes/cub3d.h"

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
	if ((*elem)->F)
		free((*elem)->F);
	if ((*elem)->C)
		free((*elem)->C);
	if (*elem)
		free(*elem);
}

void	clean_data(t_data **data)
{
	if ((*data)->view3d.img)
		free((*data)->view3d.img);
}

void	clean_all(t_data *data, int flag)
{
	//clean_element(data->player.wall_type);
	//clean_data(&data);
	clean_tab(data->map, flag);
}
