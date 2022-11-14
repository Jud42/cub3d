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
