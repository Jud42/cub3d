#include "cub3d.h"

static void	init_mapX_Y(t_ray *r)
{
	int	i;

	i = 0;
	r->mapX = ft_strlen(r->map[i]);
	while (r->map[++i])
		if (ft_strlen(r->map[i]) > r->mapX)
			r->mapX = ft_strlen(r->map[i]);
	r->mapY = i;
}

int     ft_atoi_hexe(const char *str)
{
	int	i;
    	int 	ret;
	int	len;
	int	value;
	char	c;

	i = 0;
	ret = 0;
	len = ft_strlen(str);
    	while (i < len) 
	{
        	c = str[i];
        	value = 0;
        	if (c >= '0' && c <= '9') 
            		value = c - '0';
		else if (c >= 'a' && c <= 'f')
            		value = c - 'a' + 10;
       		else if (c >= 'A' && c <= 'F')
            		value = c - 'A' + 10;
        	ret += value * pow(16, len - i - 1);
		i++;
        }
    	return (ret);
}

int	nb_line_hex(int n)
{
	int	i;

	i = 0;
	if (n <= 15 && n >= 0)
		i = 1;
	while (n != 0)
	{
		n /= 16; 
		i++;
	}
	if (i == 1)
		i++;
	return (i);
}

char	*conv_hexe(int n)
{
	char 	s[17] = "0123456789ABCDEF\0";
	char	*ret;	
	int	i;
	int	j;
	
	i = nb_line_hex(n);	
	j = i;	
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	if (n <= 15 && n >= 0)
		ret[0] = '0';
	if (n == 0)
		ret[1] = '0';
	while (n != 0)
	{
		if (n >= 16)
			ret[--i] = s[n % 16];
		else
			ret[--i] = s[n];
		n /= 16;
	}
	ret[j] = '\0';
	return (ret);

}

void	fill_map(t_ray *r)
{
	int	i;

	i = 0;
	init_mapX_Y(r);
	while (r->map[i])
	{
		if (ft_strlen(r->map[i]) < r->mapX)
		{
			int j = -1;
			char *s = malloc(sizeof(char) * r->mapX + 1);
			while (r->map[i][++j])
				s[j] = r->map[i][j];
			while (j < r->mapX)
				s[j++] = 32; //space
			s[j] = '\0';
			free(r->map[i]);
			r->map[i] = s;
		}
		i++;
	}
}
