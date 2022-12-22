#include "cub3d.h"

static void	init_mapX_Y(t_data *d)
{
	int	i;

	i = 0;
	d->mapX = ft_strlen(d->map[i]);
	while (d->map[++i])
		if (ft_strlen(d->map[i]) > d->mapX)
			d->mapX = ft_strlen(d->map[i]);
	d->mapY = i;
}

void	fill_map(t_data *d)
{
	int	i;

	i = 0;
	init_mapX_Y(d);
	while (d->map[i])
	{
		if (ft_strlen(d->map[i]) < d->mapX)
		{
			int j = -1;
			char *s = malloc(sizeof(char) * d->mapX + 1);
			while (d->map[i][++j])
				s[j] = d->map[i][j];
			while (j < d->mapX)
				s[j++] = 32; //space
			s[j] = '\0';
			free(d->map[i]);
			d->map[i] = s;
		}
		i++;
	}
}
