
#include "cub3d.h"
/*
static void	invalid_map(t_data *data, char *s)
{
	free_map(data);
	ft_printf("Error\n%s", s);
	exit(EXIT_FAILURE);
}

static void	parse_char(char c, t_data *data)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' \
	&& c != 'C' && c != 'R' && c != '\n')
		invalid_map(data, "There is an invalid character in your Map\n");
	else if (c == 'P')
		data->play_i++;
	else if (c == 'E')
		data->exit_i++;
	else if (c == 'R')
		data->patrol++;
	else if (c == 'C')
		data->total_c++;
}

static int	parse_wall(t_data *data, int i, int j)
{
	int	res;

	res = 0;
	while (data->map->map[++i] != NULL)
	{
		j = -1;
		if (ft_strnstr(data->map->map[i], "\n", data->map->x - 1))
			invalid_map(data, "There is an line break in your MAP\n");
		while (data->map->map[i][++j])
		{	
			if ((i == 0 || i == data->map->y - 1) && \
			(data->map->map[i][j] != '1' && data->map->map[i][j] != '\n'))
				invalid_map(data, "Wall is not correct\n");
			else if ((j == 0 || j == data->map->x - 1) && \
			(data->map->map[i][j] != '1' && data->map->map[i][j] != '\n'))
				invalid_map(data, "Wall is not correct\n");
			parse_char(data->map->map[i][j], data);
		}
		res += j;
	}
	res -= data->map->y;
	return (res);
}*/
/*
	data->play_i = 0;
	data->exit_i = 0;
	data->patrol = 0;
	data->total_c = 0;
	i = -1;
	j = -1;
	res = parse_wall(data, i, j);
	if (data->map->x * data->map->y != res || \
			data->map->x <= data->map->y)
		invalid_map(data, "This Map is not rectangle\n");
	else if (data->total_c == 0)
		invalid_map(data, "Object to collect missing\n");
	else if ((data->play_i != 1 || data->exit_i != 1) || data->patrol > 1)
		invalid_map(data, "You just need to have one 'P', 'E', 'R'\n");
*/
int	msg_error(char *s)
{
	printf("Error: %s", s);
	return  (1);
}

int	check_extension(const char *str, const char *substr)
{
	int	len;
	int	j;

	if (!str || !substr)
		return (1);
	else if (ft_strlen(str) == ft_strlen(substr))
		return (1);
	len = ft_strlen(str) - 1;
	j = ft_strlen(substr) - 1;
	while (j >= 0 && str[len]) 
	{
		if (str[len] == substr[j])
		{
			len--;
			j--;
		}
		else
			return (1);
	}
	return (0);
}

void	check_error_argument(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error Argument\n");
		exit(EXIT_FAILURE);
	}
	else if (check_extension(av[1], ".cub"))
	{	
		printf("Error\nMap is not valid\n");
		exit(EXIT_FAILURE);
	}
	//else if (ac > 2)
	//	ft_printf("Only 2nd argument will be taken\n");
}

/*----------------------------------------*/
int	nb_line_tab(char *file)
{
	char	*s;
	int	ret;
	int	fd;
	
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

char	*new_string(char *s)
{
	char 	*new_s;
	int	i;
	int	j;

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

void	alloc_new_tab(char **tab, char ***new_tab)
{
	int	i;
	int	n;

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

int	delete_new_line(char ***tab)
{
	int	i;
	int	n;
	char	**new_tab;

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

char	**create_tab(char *file)
{
	int	i;
	int	fd;
	char	**tab;
	
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

/*-----------------------------------*/
void	init_all(t_cube *cube, t_elements *elem)
{
	elem->NO = 0;
	elem->SO = 0;
	elem->WE = 0;
	elem->EA = 0;
	elem->F = 0;
	elem->C = 0;
	elem->N = 0;
	cube->y = 0;
	cube->x = 0;
	cube->start_map = 0;
	cube->elem = elem;
}

/*------------------------------------------*/
int	space_error(t_cube *c)
{
	int	y_tmp;

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

int	check_map_char(t_cube *c)
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
		else if (c->tab[c->y][c->x] == 'N')
			c->elem->N++;
		else if (c->tab[c->y][c->x] != '1' \
		&& c->tab[c->y][c->x] != '0' && \
		c->tab[c->y][c->x] != 'N' && c->tab[c->y][c->x] != ' ')
			return (msg_error("caracter forbidden in map\n"));
		else if (c->tab[c->y][c->x] == ' ')
			if (space_error(c))
				return (1);
	}
	if (c->elem->N > 1)
		return (msg_error("multiple player\n"));	
	return (0);
}

void	check_description(t_cube *c)
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
			if (c->tab[c->y][c->x] == '1' && !check_map_char(c))
				continue ;
			else if (c->tab[c->y][c->x])
			{
				msg_error("map :( not valid\n");
				clean_tab(c->tab, EXIT);
			}
			
		}
		c->x = 0;
		c->y++;
	}
}

/*-------------------------------------------------------*/
int	take_path(char	*line, char *substr, int *fd_elem)
{
	char	**path;
	int	i;

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

int	take_color(char *line, t_elements *elem)
{
	int	i;
	char	c;
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

int	check_char(char *line, t_cube *cube)
{
	int	ret;

	if (line[cube->x] == 'F' || line[cube->x] == 'C')
		ret = take_color(line, cube->elem);
	else if (line[cube->x] == 'N')
		ret = take_path(line, "O ", &cube->elem->NO);
	else if	(line[cube->x] == 'S')
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


void	check_element(t_cube *cube)
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
/*------------------------------------------------------*/
void	parse_map(int	ac, char **av)
{
	t_cube	cube;
	t_elements elem;

	check_error_argument(ac, av);
	cube.tab = create_tab(av[1]);
	init_all(&cube, &elem);
	check_element(&cube);
	check_description(&cube);
	clean_tab(cube.tab, 0);
	if (cube.elem->F)
		free(cube.elem->F);
	if (cube.elem->C)
		free(cube.elem->C);
}
