#include "cub3d.h"

static int     check_space(t_data *d)
{
        int     y_tmp;

        if (d->map[d->y][d->x - 1] != '1')
                return (msg_error("awall not close\n"));
        while (d->map[d->y][d->x] && d->map[d->y][d->x] == ' ')
        {
                y_tmp = d->y;
                while (y_tmp-- > 0 && \
                d->x < ft_strlen(d->map[y_tmp]) && \
                d->map[y_tmp][d->x] != '1')
                        if (d->map[y_tmp][d->x] != ' ' \
                        && d->map[y_tmp][d->x] != '1')
                                return (msg_error("bwall not close\n"));
                y_tmp = d->y;
                while (d->map[++y_tmp] && d->map[y_tmp][d->x] != '1' && \
                d->x < ft_strlen(d->map[y_tmp]))
                        if (d->map[y_tmp][d->x] != ' ' \
                        && d->map[y_tmp][d->x] != '1')
                                return (msg_error("cwall not close\n"));
                ++d->x;
        }
        if (d->map[d->y][d->x] && d->map[d->y][d->x]!= '1')
                return (msg_error("dwall not close\n"));
        return (0);
}

static int     check_position(t_data *d)
{
	char chr;

	chr = d->map[d->y][d->x];
        if (chr == 'N' || chr == 'S' || chr == 'E' || chr == 'W')
        {
                if (d->pa > -1)
                        return (msg_error("multiple position identify\n"));
                else if (chr == 'N')
                        d->pa = PI * 3 / 2;
                else if (chr == 'S')
                        d->pa = PI / 2;
                else if (chr == 'E')
                        d->pa = PI;
                else
                        d->pa = 0.0;
		d->posY = d->y * PIX;
		d->posX = d->x * PIX;
                return (0);
        }
        if (chr != '1' && chr != '0' && chr != ' ')
                return (msg_error("caracter forbidden in map\n"));
        return (0);
}

static int     check_char(t_data *d)
{
        if (d->map[d->y][ft_strlen(d->map[d->y]) - 1] != '1' && \
        d->map[d->y][ft_strlen(d->map[d->y]) - 1] != ' ')
        {
                printf("%c\n", d->map[d->y][ft_strlen(d->map[d->y]) - 1]);
                return (msg_error("wall not respected\n"));
        }
        while (d->map[d->y][++(d->x)])
        {
                if (d->y == 0 && d->map[d->y][d->x] != '1' \
                && d->map[d->y][d->x] != ' ' || !d->map[d->y + 1] \
                && d->map[d->y][d->x] != '1' && d->map[d->y][d->x] != ' ')
                {
                        printf("%c\n", d->map[d->y][d->x]);
                        return (msg_error("wall not respected\n"));
                }
                else if (check_position(d))
                        return (1);
                else if (d->map[d->y][d->x] == ' ')
                        if (check_space(d))
                                return (1);
        }
        return (0);
}

int	parse_map(t_data *d)
{
        d->y = -1;
        d->x = 0;
        while (d->map[++d->y])
        {
                while (d->map[d->y][d->x])
                {
                        while (d->map[d->y][d->x] == ' ')
                                d->x++;
                        if (d->map[d->y][d->x] && d->map[d->y][d->x] != '1') 
                                return (msg_error("map :( not valid\n"));
                        if (check_char(d))
                        	return (1);
                }
                d->x = 0;
        }
		fill_map(d);
	return (0);
}
