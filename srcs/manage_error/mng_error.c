
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

