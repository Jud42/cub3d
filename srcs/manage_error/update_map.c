#include "../../includes/cub3d.h"

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

static int     check_char(char *line, t_ray *r, int *elem)
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
        printf("%c\n", line[r->x]);
        return(msg_error("unrecognized identifier\n"));
    }
    if (ret == 0)
        r->x = ft_strlen(line);
    (*elem)++;
    return (ret);
}

static int	update_map(t_ray *r)
{
    int	i;
    char	**new_map;

    if (!r->map[r->y])
        return(msg_error("map not valid\n"));
    i = -1;
    while (r->map[++i])
        ;
    new_map = malloc(sizeof(char *) * (i - r->y) + 1);
    if (!new_map)
        return(msg_error("malloc() update_map()\n"));
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
    int	elem;

    wall = 0;
    elem = 0;
    while (!wall && r->map[++r->y])
    {
        while (!wall && r->map[r->y][r->x])
        {
            if (r->map[r->y][r->x] == ' ')
                r->x++;
            else if (r->map[r->y][r->x] == '1')
                wall = 1;
            else if (check_char(r->map[r->y], r, &elem) == 1)
                return (1);
        }
        r->x = 0;
    }
    if (elem)
        return(update_map(r));
    return (0);
}