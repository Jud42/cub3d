#include "../includes/cub3d.h"

static int     nb_line_tab(char *file)
{
        char    *s;
        int     ret;
        int     fd;

        fd = open(file, O_RDONLY);
        if (fd < 0)
                msg_error("error open() file", EXIT);
        s = get_next_line(fd);
        if (!s)
                msg_error("error Empty file", EXIT);
        ret = 0;
        while (s != NULL)
        {
                ret++;
                free(s);
                s = get_next_line(fd);
        }
        close(fd);
        return (ret);
}

static char    *new_string(char *s)
{
        char    *new_s;
        int     i;
        int     j;

        new_s = malloc(sizeof(char) * ft_strlen(s));
        if (!new_s)
        {
                msg_error("malloc() delete_new_line", 0);
                return (NULL);
        }
        i = -1;
        j = 0;
        while (s[++i])
        {
                if (s[i] == '\n')
                        continue ;
                else
                        new_s[j++] = s[i];
        }
        new_s[j] = '\0';
        return (new_s);
}

static int	first_char(char *s)
{
	int	i;
        
	if (!ft_strncmp(s, "\n", ft_strlen(s)))
		return (0);
	i = -1;
	while (s[++i] && s[i] == ' ')
		;
	if (s[i] == '1')
		return (1);
	return (0);
}

static void    alloc_new_tab(char **tab, char ***new_tab)
{
        int     i;
        int     n;

        i = -1;
        n = 0;
        while (tab[++i])
                if (!ft_strncmp(tab[i], "\n", ft_strlen(tab[i])))
                        n++;
        if (i - n != 0)
        {
                *new_tab = malloc(sizeof(char *) * (i + 1 - n));
                if (!*new_tab)
                {
                        msg_error("malloc(): delete_new_line()", 0);
                        clean_tab(tab, EXIT);
                }
                return ;
        }
        msg_error("map format '\\n'", 0);
        clean_tab(tab, EXIT);
}


static char	**delete_new_line(char **tab)
{
        int     i;
        int     n;
        char    **new_tab;

        alloc_new_tab(tab, &new_tab);
        i = -1;
        n = 0;
        while (tab[++i])
        {
		if (!ft_strncmp(tab[i], "\n", ft_strlen(tab[i])))
                        continue ;
                else
                {
                        new_tab[n] = new_string(tab[i]);
                        if (!new_tab[n++])
                        {
                                clean_tab(tab, 0);
                                clean_tab(new_tab, EXIT);
                        }
                }
        }
        new_tab[n] = NULL;
        clean_tab(tab, 0);
	return (new_tab);
}

char    **create_tab(char *file)
{
        int     i;
        int     fd;
        char    **tab;

        tab = malloc(sizeof(char *) * (nb_line_tab(file) + 1));
        if (!tab)
                msg_error("malloc tab in create_tab()", EXIT);
        fd = open(file, O_RDONLY);
	if (fd < 0)
		msg_error("file not found", EXIT);
        i = 0;
        tab[i] = get_next_line(fd);
        while (tab[i++])
                tab[i] = get_next_line(fd);
        close(fd);
        if (tab[0][ft_strlen(tab[0]) - 1] == '\n')
                return (delete_new_line(tab));
        return (tab);
}
