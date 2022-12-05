#include "cub3d.h"

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
	//if ((*data)->mlx_ptr)
	//	free((*data)->mlx_ptr);
	//if ((*data)->mlx_win)
	//	free((*data)->mlx_win);
	if (*data)
		free(*data);


}

void	clean_all(t_cube *cube, int flag)
{
	clean_element(&cube->elem);
	clean_data(&cube->data);
	clean_tab(cube->map, flag);
}
