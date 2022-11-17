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

void	clean_all(t_cube *cube, int flag)
{
	if (cube->elem->F)
		free(cube->elem->F);
	if (cube->elem->C)
		free(cube->elem->C);
	clean_tab(cube->tab, flag);
}
