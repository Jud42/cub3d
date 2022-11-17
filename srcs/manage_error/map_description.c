#include "cub3d.h"

static int     space_error(t_cube *c)
{
        int     y_tmp;

        if (c->tab[c->y][c->x - 1] != '1')
                return (msg_error("awall not close\n"));
        while (c->tab[c->y][c->x] && c->tab[c->y][c->x] == ' ')
        {
                y_tmp = c->y;
                while (y_tmp-- > c->start_map && \
                c->x < ft_strlen(c->tab[y_tmp]) && \
                c->tab[y_tmp][c->x] != '1')
                        if (c->tab[y_tmp][c->x] != ' ' \
                        && c->tab[y_tmp][c->x] != '1')
                                return (msg_error("bwall not close\n"));
                y_tmp = c->y;
                while (c->tab[++y_tmp] && c->tab[y_tmp][c->x] != '1' && \
                c->x < ft_strlen(c->tab[y_tmp]))
                        if (c->tab[y_tmp][c->x] != ' ' \
                        && c->tab[y_tmp][c->x] != '1')
                                return (msg_error("cwall not close\n"));
                ++c->x;
        }
        if (c->tab[c->y][c->x] && c->tab[c->y][c->x]!= '1')
                return (msg_error("dwall not close\n"));
        return (0);
}

static int     parse_char(char c, t_elements *elem)
{
        if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        {
                if (elem->N + elem->S + elem->E + elem->W >= 1)
                        return (msg_error("multiple position identify\n"));
                else if (c == 'N')
                        elem->N++;
                else if (c == 'S')
                        elem->S++;
                else if (c == 'E')
                        elem->E++;
                else
                        elem->W++;
                return (0);
        }
        if (c != '1' && c != '0' && c != ' ')
                return (msg_error("caracter forbidden in map\n"));
        return (0);
}

static int     check_map_char(t_cube *c)
{
        if (c->tab[c->y][ft_strlen(c->tab[c->y]) - 1] != '1' && \
        c->tab[c->y][ft_strlen(c->tab[c->y]) - 1] != ' ')
        {
                printf("%c\n", c->tab[c->y][ft_strlen(c->tab[c->y]) - 1]);
                return (msg_error("wall not respected\n"));
        }
        while (c->tab[c->y][++(c->x)])
        {
                if (c->y == c->start_map && c->tab[c->y][c->x] != '1' \
                && c->tab[c->y][c->x] != ' ' || !c->tab[c->y + 1] \
                && c->tab[c->y][c->x] != '1' && c->tab[c->y][c->x] != ' ')
                {
                        printf("%c\n", c->tab[c->y][c->x]);
                        return (msg_error("wall not respected\n"));
                }
                else if (parse_char(c->tab[c->y][c->x], c->elem))
                        return (1);
                else if (c->tab[c->y][c->x] == ' ')
                        if (space_error(c))
                                return (1);
        }
        return (0);
}

void    check_description(t_cube *c)
{
        if (!c->tab[c->y])
        {
                msg_error("map :( not valid\n");
                clean_tab(c->tab, EXIT);
        }
        c->start_map = c->y;
        while (c->tab[c->y])
        {
                while (c->tab[c->y][c->x])
                {
                        while (c->tab[c->y][c->x] == ' ')
                                c->x++;
                        if (c->tab[c->y][c->x] && c->tab[c->y][c->x] != '1') 
                        {
                                msg_error("map :( not valid\n");
                                clean_tab(c->tab, EXIT);
                        }
                        if (check_map_char(c))
                                return ;

                }
                c->x = 0;
                c->y++;
        }
        c->x = 0;
        c->y = 0;
}
