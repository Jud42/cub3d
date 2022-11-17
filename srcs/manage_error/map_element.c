#include "cub3d.h"

static int     take_path(char  *line, char *substr, int *fd_elem)
{
        char    **path;
        int     i;

        i = -1;
        while (line[++i] && line[i] == ' ')
                ;
        if (line[i + 1] == substr[0] && line[i + 2] == substr[1])
        {
                if (*fd_elem)
                        return(msg_error("same identifiant find twice\n"));
                path = ft_split(line, ' ');
                if (!path || !path[1] || path[2] != NULL)
                {
                        clean_tab(path, 0);
                        return (msg_error("format path not valid\n"));
                }
                *fd_elem = open(path[1], O_RDONLY);
                if (*fd_elem < 0)
                {
                        clean_tab(path, 0);
                        return (msg_error("open(): path not_found\n"));
                }
                clean_tab(path, 0);
                return (0);
        }
        return (msg_error("unrecognized identifier\n"));
}

static int     take_color(char *line, t_elements *elem)
{
        int     i;
        char    c;
        char **tab_one;
        char **tab_two;
        int *temp;

        i = -1;
        /*------------dont forget to =FREE= elem=>COLOR----------*/
        while (line[++i] && line[i] == ' ')
                ;
        c = line[i];
        if (line[i] == 'F' || line[i] == 'C' && line[i + 1] == ' ')
        {
                tab_one = ft_split(line, ' ');
                if (!tab_one || !tab_one[1] || tab_one[2] != NULL)
                        return(msg_error("format color not valid\n"));
                tab_two = ft_split(tab_one[1], ',');
                if (!tab_two || !tab_two[1] || !tab_two[2] || tab_two[3])
                {
                        clean_tab(tab_one, 0);
                        return(msg_error("format color not valid\n"));
                }
                temp = malloc(sizeof(int) * 3);
                if (!temp)
                {
                        clean_tab(tab_one, 0);
                        clean_tab(tab_two, 0);
                        return(msg_error("malloc(): in take_color\n"));
                }
                i = -1;
                while (++i < 3)
                        temp[i] = ft_atoi(tab_two[i]);
                if (c == 'F')
                        elem->F = temp;
                else
                        elem->C = temp;
                clean_tab(tab_one, 0);
                clean_tab(tab_two, 0);
                return (0);
        }
        return(msg_error("unrecognized identifier\n"));
}

static int     check_char(char *line, t_cube *cube)
{
        int     ret;

        if (line[cube->x] == 'F' || line[cube->x] == 'C')
                ret = take_color(line, cube->elem);
        else if (line[cube->x] == 'N')
                ret = take_path(line, "O ", &cube->elem->NO);
        else if (line[cube->x] == 'S')
                ret = take_path(line, "O ", &cube->elem->SO);
        else if (line[cube->x] == 'E')
                ret = take_path(line, "A ", &cube->elem->EA);
        else if (line[cube->x] == 'W')
                ret = take_path(line, "E ", &cube->elem->WE);
        else 
        {
                printf("%c\n", line[cube->x]);
                return(msg_error("unrecognized identifier\n"));
        }
        if (ret == 0)
                cube->x = ft_strlen(line);
        return (ret);
}


void    check_elements(t_cube *cube)
{
        while (cube->tab[cube->y])
        {
                while (cube->tab[cube->y][cube->x])
                {
                        if (cube->tab[cube->y][cube->x] == '1')
                                return ;
                        else if (cube->tab[cube->y][cube->x] == ' ')
                                cube->x++;
                        else if (check_char(cube->tab[cube->y], cube) == 1)
                                clean_tab(cube->tab, EXIT);
                }
                cube->x = 0;
                cube->y++;
        }
}

