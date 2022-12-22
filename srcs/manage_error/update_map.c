#include "cub3d.h"

static int     take_path(char  *line, char *substr, void **texture)
{
        char    **path;
        int     i;

        i = -1;
        while (line[++i] && line[i] == ' ')
                ;
        if (line[i + 1] == substr[0] && line[i + 2] == substr[1])
        {
                if (*texture)
                        return(msg_error("same identifiant find twice\n"));
                path = ft_split(line, ' ');
                if (!path || !path[1] || path[2] != NULL)
                {
                        clean_tab(path, 0);
                        return (msg_error("format path not valid\n"));
                }
                *texture = ft_strdup(path[1]);
                clean_tab(path, 0);
                return (0);
        }
        return (msg_error("unrecognized identifier\n"));
}

static int     take_color(char *line, t_elements *elem)
{
        int     i;
        char    c;
        char **map_one;
        char **map_two;
        int *temp;

        i = -1;
        /*------------dont forget to =FREE= elem=>COLOR----------*/
        while (line[++i] && line[i] == ' ')
                ;
        c = line[i];
        if (line[i] == 'F' || line[i] == 'C' && line[i + 1] == ' ')
        {
                map_one = ft_split(line, ' ');
                if (!map_one || !map_one[1] || map_one[2] != NULL)
                        return(msg_error("format color not valid\n"));
                map_two = ft_split(map_one[1], ',');
                if (!map_two || !map_two[1] || !map_two[2] || map_two[3])
                {
                        clean_tab(map_one, 0);
                        return(msg_error("format color not valid\n"));
                }
                temp = malloc(sizeof(int) * 3);
                if (!temp)
                {
                        clean_tab(map_one, 0);
                        clean_tab(map_two, 0);
                        return(msg_error("malloc(): in take_color\n"));
                }
                i = -1;
                while (++i < 3)
                        temp[i] = ft_atoi(map_two[i]);
                if (c == 'F')
                        elem->F = temp;
                else
                        elem->C = temp;
                clean_tab(map_one, 0);
                clean_tab(map_two, 0);
                return (0);
        }
        return(msg_error("unrecognized identifier\n"));
}

static int     check_char(char *line, t_data *d, int *elem)
{
        int     ret;

        if (line[d->x] == 'F' || line[d->x] == 'C')
                ret = take_color(line, d->elem);
        else if (line[d->x] == 'N')
                ret = take_path(line, "O ", &d->elem->NO);
        else if (line[d->x] == 'S')
                ret = take_path(line, "O ", &d->elem->SO);
        else if (line[d->x] == 'E')
                ret = take_path(line, "A ", &d->elem->EA);
        else if (line[d->x] == 'W')
                ret = take_path(line, "E ", &d->elem->WE);
        else 
        {
                printf("%c\n", line[d->x]);
                return(msg_error("unrecognized identifier\n"));
        }
        if (ret == 0)
                d->x = ft_strlen(line);
	(*elem)++;
        return (ret);
}

static int	update_map(t_data *d)
{
	int	i;
	char	**new_map;

	if (!d->map[d->y])
		return(msg_error("map not valid\n"));
	i = -1;
	while (d->map[++i])
		;
	new_map = malloc(sizeof(char *) * (i - d->y) + 1);
	if (!new_map)
		return(msg_error("malloc() update_map()\n"));
	i = 0;
	while (d->map[d->y])
		new_map[i++] = ft_strdup(d->map[d->y++]);
	new_map[i] = NULL;
	clean_tab(d->map, 0);
	d->map = new_map;
	return (0);
}

int    take_map(t_data *d)
{
	int	wall;
	int	elem;

	wall = 0;
	elem = 0;
        while (!wall && d->map[++d->y])
        {
                while (!wall && d->map[d->y][d->x])
                {
                        if (d->map[d->y][d->x] == ' ')
                                d->x++;
                        else if (d->map[d->y][d->x] == '1')
                                wall = 1;
                        else if (check_char(d->map[d->y], d, &elem) == 1)
				return (1);
                }
                d->x = 0;
        }
	if (elem)
		return(update_map(d));
	return (0);
}

