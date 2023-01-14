#include "../includes/cub3d.h"
static void	init_mapX_Y(t_ray *r)
{
	int	i;

	i = 0;
	r->mapX = ft_strlen(r->map[i]);
	while (r->map[++i])
		if (ft_strlen(r->map[i]) > r->mapX)
			r->mapX = ft_strlen(r->map[i]);
	r->mapY = i;
}

void	fill_map(t_ray *r)
{
	int	i;

	i = 0;
	init_mapX_Y(r);
	while (r->map[i])
	{
		if (ft_strlen(r->map[i]) < r->mapX)
		{
			int j = -1;
			char *s = malloc(sizeof(char) * r->mapX + 1);
			while (r->map[i][++j])
				s[j] = r->map[i][j];
			while (j < r->mapX)
				s[j++] = 32; //space
			s[j] = '\0';
			free(r->map[i]);
			r->map[i] = s;
		}
		i++;
	}
}
