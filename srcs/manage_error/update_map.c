#include "cub3d.h"

static int     take_path(char  *line, char *substr, char **texture)
{
        char    **path;
        int     i;

        i = -1;
        while (line[++i] && line[i] == ' ')
                ;
        if (line[i + 1] == substr[0] && line[i + 2] == substr[1])
        {
                if (*texture)
                        return(msg_error("same identifiant find twice", 0));
                path = ft_split(line, ' ');
                if (!path || !path[1] || path[2] != NULL)
                {
                        clean_tab(path, 0);
                        return (msg_error("format path texture", 0));
                }
                *texture = ft_strdup(path[1]);
                clean_tab(path, 0);
                return (0);
        }
        return (msg_error("unrecognized identifier", 0));
}

static int     check_char(char *line, t_ray *r, int *nb_elem)
{
        int     ret;

	ret = 0;
        if (line[r->x] == 'F' || line[r->x] == 'C')
                ret = take_color(line, r->elem);
        else if (line[r->x] == 'N')
                ret = take_path(line, "O ", &r->elem->NO);
        else if (line[r->x] == 'S')
                ret = take_path(line, "O ", &r->elem->SO);
        else if (line[r->x] == 'E')
                ret = take_path(line, "A ", &r->elem->EA);
        else if (line[r->x] == 'W')
                ret = take_path(line, "E ", &r->elem->WE);
        else 
        {
                ft_putchar_fd(line[r->x], 1);
                ft_putchar_fd('\n', 1);
                return(msg_error("unrecognized identifier", 0));
        }
        if (ret == 0)
                r->x = ft_strlen(line);
	(*nb_elem)++;
        return (ret);
}

static int	update_map(t_ray *r)
{
	int	i;
	char	**new_map;

	if (!r->map[r->y])
		return(msg_error("map not valid", 0));
	i = -1;
	while (r->map[++i])
		;
	new_map = malloc(sizeof(char *) * (i - r->y) + 1);
	if (!new_map)
		return(msg_error("malloc() update_map()", 0));
	i = 0;
	while (r->map[r->y])
		new_map[i++] = ft_strdup(r->map[r->y++]);
	new_map[i] = NULL;
	clean_tab(r->map, 0);
	r->map = new_map;
	return (0);
}

int    take_map(t_ray *r)
{
	int	wall;
	int	nb_elem;

	wall = 0;
	nb_elem = 0;
        while (!wall && r->map[++r->y])
        {
                while (!wall && r->map[r->y][r->x])
                {
                        if (r->map[r->y][r->x] == ' ')
                                r->x++;
                        else if (r->map[r->y][r->x] == '1')
                                wall = 1;
                        else if (check_char(r->map[r->y], r, &nb_elem) == 1)
				return (1);
                }
                r->x = 0;
        }
	if (nb_elem)
		return(update_map(r));
	return (0);
}

