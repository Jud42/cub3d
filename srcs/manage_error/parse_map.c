#include "../../includes/cub3d.h"

static int     check_space(t_ray *r)
{
    int     y_tmp;

    if (r->map[r->y][r->x - 1] != '1')
        return (msg_error("awall not close\n"));
    while (r->map[r->y][r->x] && r->map[r->y][r->x] == ' ')
    {
        y_tmp = r->y;
        while (y_tmp-- > 0 && \
                r->x < ft_strlen(r->map[y_tmp]) && \
                r->map[y_tmp][r->x] != '1')
            if (r->map[y_tmp][r->x] != ' ' \
                        && r->map[y_tmp][r->x] != '1')
                return (msg_error("bwall not close\n"));
        y_tmp = r->y;
        while (r->map[++y_tmp] && r->map[y_tmp][r->x] != '1' && \
                r->x < ft_strlen(r->map[y_tmp]))
            if (r->map[y_tmp][r->x] != ' ' \
                        && r->map[y_tmp][r->x] != '1')
                return (msg_error("cwall not close\n"));
        ++r->x;
    }
    if (r->map[r->y][r->x] && r->map[r->y][r->x]!= '1')
        return (msg_error("dwall not close\n"));
    return (0);
}

static int     check_position(t_ray *r)
{
    char c;

    c = r->map[r->y][r->x];
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
    {
        if (r->pa > -1)
            return (msg_error("multiple position identify\n"));
        else if (c == 'N')
            r->pa = PI * 3 / 2;
        else if (c == 'S')
            r->pa = PI / 2;
        else if (c == 'E')
            r->pa = PI;
        else
            r->pa = 0.0;
        r->posY = (double)r->y + 0.5;
        r->posX = (double)r->x + 0.5;
        r->map[r->y][r->x] = '0';
        r->pos = c;
        return (0);
    }
    if (c != '1' && c != '0' && c != ' ')
        return (msg_error("caracter forbidden in map\n"));
    return (0);
}

static int     check_char(t_ray *r)
{
    if (r->map[r->y][ft_strlen(r->map[r->y]) - 1] != '1' && \
        r->map[r->y][ft_strlen(r->map[r->y]) - 1] != ' ')
    {
        printf("%c\n", r->map[r->y][ft_strlen(r->map[r->y]) - 1]);
        return (msg_error("wall not respected\n"));
    }
    while (r->map[r->y][++(r->x)])
    {
        if (r->y == 0 && r->map[r->y][r->x] != '1' \
                && r->map[r->y][r->x] != ' ' || !r->map[r->y + 1] \
                && r->map[r->y][r->x] != '1' && r->map[r->y][r->x] != ' ')
        {
            printf("%c\n", r->map[r->y][r->x]);
            return (msg_error("wall not respected\n"));
        }
        else if (check_position(r))
            return (1);
        else if (r->map[r->y][r->x] == ' ')
            if (check_space(r))
                return (1);
    }
    return (0);
}

int	parse_map(t_ray *r)
{
    r->y = -1;
    r->x = 0;
    while (r->map[++r->y])
    {
        while (r->map[r->y][r->x])
        {
            while (r->map[r->y][r->x] == ' ')
                r->x++;
            if (r->map[r->y][r->x] && r->map[r->y][r->x] != '1')
                return (msg_error("map :( not valid\n"));
            if (check_char(r))
                return (1);
        }
        r->x = 0;
    }
    fill_map(r);
    return (0);
}
