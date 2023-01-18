#include "libft.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

static char	*stradd(char *s, char c)
{
    char	*p;
    int		len;
    int		i;
    if(!s)
        return (NULL);
    len = ft_strlen(s);
    p = malloc((len + 2) * sizeof(char));
    if (!p)
    {
        if (s)
            free(s);
        return (NULL);
    }
    i = -1;
    while (++i < len)
        p[i] = s[i];
    if (s)
        free (s);
    p[i] = c;
    p[i + 1] = '\0';
    return (p);
}

static	bool	init(int fd, t_type *buf)
{
    buf->fd = fd;
    buf->max = read(buf->fd, &buf->data, 1);
    buf->pos = -1;
    return (buf->max >= 0);
}

static	char	read_buf(t_type *buf)
{
    if (++(buf->pos) == buf->max)
    {
        buf->max = read(buf->fd, &buf-> data, 1);
        buf->pos = 0;
    }
    if (!buf->max)
        return (0);
    return (buf->data);
}

char	*get_next_line(int fd)
{
    static t_type	buf;
    char			*line;
    char			c;

    buf.fd = -1;
    if (buf.fd != fd)
        if (!init(fd, &buf))
            return (NULL);
    line = 0;
    c = read_buf(&buf);
    printf("c = %c\n", c);
    while (c)
    {
        line = stradd(line, c);
        printf("line = %s\n", line);
        if (c == '\n')
            return (line);
        c = read_buf(&buf);
    }
    return (line);
}