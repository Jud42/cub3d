#include "cub3d.h"

static int     nb_line_tab(char *file)
{
        char    *s;
        int     ret;
        int     fd;

        fd = open(file, O_RDONLY);
        if (fd < 0)
        {
                printf("error open() .cub\n");
                exit (EXIT_FAILURE);
        }
        s = get_next_line(fd);
        if (!s)
        {
                printf("error Empty file\n");
                exit(1);
        }
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
                msg_error("malloc() delete_new_line\n");
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

static void    alloc_new_tab(char **tab, char ***new_tab)
{
        int     i;
        int     n;

        i = -1;
        n = 0;
        while (tab[++i])
                if (tab[i] == "\n")
                        n++;
        if (i - n != 0)
        {
                *new_tab = malloc(sizeof(char *) * (i + 1 - n));
                if (!*new_tab)
                {
                        msg_error("malloc(): delete_new_line()\n");
                        clean_tab(tab, EXIT);
                }
                return ;
        }
        msg_error("map format '\\n'\n");
        clean_tab(tab, EXIT);
}

static int     delete_new_line(char ***tab)
{
        int     i;
        int     n;
        char    **new_tab;

        alloc_new_tab(*tab, &new_tab);
        i = -1;
        n = 0;
        while ((*tab)[++i])
        {
                if (!ft_strncmp((*tab)[i], "\n", ft_strlen((*tab)[i])))
                        continue ;
                else
                {
                        new_tab[n] = new_string((*tab)[i]);
                        if (!new_tab[n++])
                        {
                                clean_tab(*tab, 0);
                                clean_tab(new_tab, EXIT);
                        }
                }
        }
        new_tab[n] = NULL;
        clean_tab(*tab, 0);
        *tab = new_tab;
        return (0);
}

char    **create_tab(char *file)
{
        int     i;
        int     fd;
        char    **tab;

        tab = malloc(sizeof(char *) * (nb_line_tab(file) + 1));
        if (!tab)
        {
                printf("erro malloc_tab\n");
                exit(1);
        }
        fd = open(file, O_RDONLY);
        i = 0;
        tab[i] = get_next_line(fd);
        while (tab[i++])
                tab[i] = get_next_line(fd);
        if (tab[0][ft_strlen(tab[0]) - 1] == '\n')
                delete_new_line(&tab);
        close(fd);
        return (tab);
}
