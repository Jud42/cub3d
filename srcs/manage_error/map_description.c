#include "cub3d.h"

static int     check_space(t_cube *c)
{
        int     y_tmp;

        if (c->map[c->y][c->x - 1] != '1')
                return (msg_error("awall not close\n"));
        while (c->map[c->y][c->x] && c->map[c->y][c->x] == ' ')
        {
                y_tmp = c->y;
                while (y_tmp-- > 0 && \
                c->x < ft_strlen(c->map[y_tmp]) && \
                c->map[y_tmp][c->x] != '1')
                        if (c->map[y_tmp][c->x] != ' ' \
                        && c->map[y_tmp][c->x] != '1')
                                return (msg_error("bwall not close\n"));
                y_tmp = c->y;
                while (c->map[++y_tmp] && c->map[y_tmp][c->x] != '1' && \
                c->x < ft_strlen(c->map[y_tmp]))
                        if (c->map[y_tmp][c->x] != ' ' \
                        && c->map[y_tmp][c->x] != '1')
                                return (msg_error("cwall not close\n"));
                ++c->x;
        }
        if (c->map[c->y][c->x] && c->map[c->y][c->x]!= '1')
                return (msg_error("dwall not close\n"));
        return (0);
}

static int     check_position(char c, t_elements *elem)
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

static int     check_char(t_cube *c)
{
        if (c->map[c->y][ft_strlen(c->map[c->y]) - 1] != '1' && \
        c->map[c->y][ft_strlen(c->map[c->y]) - 1] != ' ')
        {
                printf("%c\n", c->map[c->y][ft_strlen(c->map[c->y]) - 1]);
                return (msg_error("wall not respected\n"));
        }
        while (c->map[c->y][++(c->x)])
        {
                if (c->y == 0 && c->map[c->y][c->x] != '1' \
                && c->map[c->y][c->x] != ' ' || !c->map[c->y + 1] \
                && c->map[c->y][c->x] != '1' && c->map[c->y][c->x] != ' ')
                {
                        printf("%c\n", c->map[c->y][c->x]);
                        return (msg_error("wall not respected\n"));
                }
                else if (check_position(c->map[c->y][c->x], c->elem))
                        return (1);
                else if (c->map[c->y][c->x] == ' ')
                        if (check_space(c))
                                return (1);
        }
        return (0);
}

int	parse_map(t_cube *c)
{
        c->y = -1;
        c->x = 0;
        while (c->map[++c->y])
        {
                while (c->map[c->y][c->x])
                {
                        while (c->map[c->y][c->x] == ' ')
                                c->x++;
                        if (c->map[c->y][c->x] && c->map[c->y][c->x] != '1') 
                                return (msg_error("map :( not valid\n"));
                        if (check_char(c))
                        	return (1);
                }
                c->x = 0;
        }
	return (0);
}
