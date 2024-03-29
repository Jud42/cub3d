/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:29:21 by rmamison          #+#    #+#             */
/*   Updated: 2023/02/03 21:06:10 by btchiman         ###   42Lausanne.ch     */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*new_string(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	new_s = malloc(sizeof(char) * ft_strlen(s)+1);
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

static void	alloc_new_tab(char **tab, char ***new_tab)
{
	int	i;
	int	n;

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
	int		i;
	int		n;
	char	**new_tab;

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

char	**create_tab(char *file)
{
	int		i;
	int		fd;
	char	**tab;

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
